#include <string>
#include <cstring>  // for wcscpy_s, wcscat_s
#include <cstdlib>  // for _countof
#include <iostream> // for cout, includes <cstdlib>, <cstring>
#include <errno.h>  // for return values
#include <ctime>


using std::cout;
using std::endl;
using std::cin;

#include "Header.h"
#include "Source.h"



// 1 Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным
// и написать программу, которая:
// 1.1.создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями;
// 1.2.рассчитает, какой процент из созданных деревьев является сбалансированными.

/*Программа для проверки того, сбалансировано ли данное двоичное дерево как красно - черное дерево */

struct Node{

    int key;

    Node* left, * right;

};


/*утилита, которая выделяет новый узел с данным ключом*/

Node * newNode(int key){

    Node* node = new Node;

    node->key = key;

    node->left = node->right = NULL;

    return (node);

}


// Возвращает дерево возврата, если двоичное дерево сбалансировано как красно-черное
// дерево. Эта функция также устанавливает значение в maxh и minh (передается
// ссылка). maxh и minh устанавливаются как максимальная и минимальная высота корня.

bool isBalancedUtil(Node* root, int& maxh, int& minh){

    // Базовый вариант

    if (root == NULL){

        maxh = minh = 0;

        return true;
    }


    int lmxh, lmnh; // Для сохранения максимальной и минимальной высоты левого поддерева
    int rmxh, rmnh; // Для сохранения максимальной и минимальной высоты правого поддерева



    // Проверить, сбалансировано ли левое поддерево, также установить lmxh и lmnh

    if (isBalancedUtil(root->left, lmxh, lmnh) == false)
        return false;


    // Проверить, сбалансировано ли правое поддерево, также установить rmxh и rmnh

    if (isBalancedUtil(root->right, rmxh, rmnh) == false)
        return false;

    // Устанавливаем максимальную и минимальную высоты этого узла для родительского вызова

    maxh = std::max(lmxh, rmxh) + 1;
    minh = std::min(lmnh, rmnh) + 1;

    // Посмотрим, сбалансирован ли этот узел

    if (maxh <= 2 * minh)
        return true;

    return false;
}


// Обёртка над isBalancedUtil ()

bool isBalanced(Node* root){

    int maxh, minh;

    return isBalancedUtil(root, maxh, minh);

}


Node* insert(Node* root, int key){

    // Создаем новый узел, содержащий
    // новый элемент
    Node* newnode = newNode(key);

    // Указатель для начала обхода от root и
    // проходит нисходящий путь к поиску
    // где новый узел для вставки
    Node* x = root;

    // Указатель у поддерживает трейлинг
    // указатель x
    Node* y = NULL;

    while (x != NULL) {

        y = x;

        if (key < x->key)

            x = x->left;

        else

            x = x->right;

    }

    // Если корень NULL, т.е. дерево пустое
    // Новый узел является корневым узлом
    if (y == NULL)
        y = newnode;

    // Если новый ключ меньше, чем ключ конечного узла
    // Назначаем новый узел своим левым потомком
    else if (key < y->key)
        y->left = newnode;

    // еще назначаем новому узлу его правого потомка
    else
        y->right = newnode;

    // Возвращает указатель где
    // новый узел вставлен
    return y;

}

void CreateForest(Node *root,int tree_size, int node_size) {

    for (int i = 0; i < tree_size; ++i) {
        srand(time(NULL));
        Node* pt_root = newNode(rand() % 10000);
        root[i] = *pt_root;
        for (int j = 0; j < node_size; ++j) {
            insert(&root[i], rand() % 10000);
        }
    }
}

float Balancing_percentage(Node* root, int tree_size, int node_size) {

    int sumTrueBalans = 0;
    for (int i = 0; i < tree_size; i++) {

        if (isBalanced(&root[i]))
            sumTrueBalans++;

    }

    return  (sumTrueBalans * 100) / tree_size;
}

// 2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.

bool search(Node* x, int k) {
    if (x == NULL)
        return false;
    if (x->key == k )
        return true;
    if (k < x->key)
        return search(x->left, k);
    else
        return search(x->right, k);
    return false;
}

//---------------------------------------------------------------------------------------------------------------
void printBinTree(Node* root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
    
}

// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.
int main(){

    const int tree_size = 50;
    const int node_size = 10000;
    Node root[tree_size] = {};
    CreateForest(root, tree_size, node_size);
    cout << "Result :  " << Balancing_percentage(root, tree_size, node_size) << " %" << endl;
    cout << search(&root[0], 333) << endl;
    return 0;

}