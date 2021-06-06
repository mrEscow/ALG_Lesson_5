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



// 1 �������� ������� ����������� �������� �� ���������� � �� �������� ������ ����������������
// � �������� ���������, �������:
// 1.1.�������[50] �������� ��[10000] ����� � �������� ���� ���������� �������������� ����������;
// 1.2.����������, ����� ������� �� ��������� �������� �������� �����������������.

/*��������� ��� �������� ����, �������������� �� ������ �������� ������ ��� ������ - ������ ������ */

struct Node{

    int key;

    Node* left, * right;

};


/*�������, ������� �������� ����� ���� � ������ ������*/

Node * newNode(int key){

    Node* node = new Node;

    node->key = key;

    node->left = node->right = NULL;

    return (node);

}


// ���������� ������ ��������, ���� �������� ������ �������������� ��� ������-������
// ������. ��� ������� ����� ������������� �������� � maxh � minh (����������
// ������). maxh � minh ��������������� ��� ������������ � ����������� ������ �����.

bool isBalancedUtil(Node* root, int& maxh, int& minh){

    // ������� �������

    if (root == NULL){

        maxh = minh = 0;

        return true;
    }


    int lmxh, lmnh; // ��� ���������� ������������ � ����������� ������ ������ ���������
    int rmxh, rmnh; // ��� ���������� ������������ � ����������� ������ ������� ���������



    // ���������, �������������� �� ����� ���������, ����� ���������� lmxh � lmnh

    if (isBalancedUtil(root->left, lmxh, lmnh) == false)
        return false;


    // ���������, �������������� �� ������ ���������, ����� ���������� rmxh � rmnh

    if (isBalancedUtil(root->right, rmxh, rmnh) == false)
        return false;

    // ������������� ������������ � ����������� ������ ����� ���� ��� ������������� ������

    maxh = std::max(lmxh, rmxh) + 1;
    minh = std::min(lmnh, rmnh) + 1;

    // ���������, ������������� �� ���� ����

    if (maxh <= 2 * minh)
        return true;

    return false;
}


// ������ ��� isBalancedUtil ()

bool isBalanced(Node* root){

    int maxh, minh;

    return isBalancedUtil(root, maxh, minh);

}


Node* insert(Node* root, int key){

    // ������� ����� ����, ����������
    // ����� �������
    Node* newnode = newNode(key);

    // ��������� ��� ������ ������ �� root �
    // �������� ���������� ���� � ������
    // ��� ����� ���� ��� �������
    Node* x = root;

    // ��������� � ������������ ��������
    // ��������� x
    Node* y = NULL;

    while (x != NULL) {

        y = x;

        if (key < x->key)

            x = x->left;

        else

            x = x->right;

    }

    // ���� ������ NULL, �.�. ������ ������
    // ����� ���� �������� �������� �����
    if (y == NULL)
        y = newnode;

    // ���� ����� ���� ������, ��� ���� ��������� ����
    // ��������� ����� ���� ����� ����� ��������
    else if (key < y->key)
        y->left = newnode;

    // ��� ��������� ������ ���� ��� ������� �������
    else
        y->right = newnode;

    // ���������� ��������� ���
    // ����� ���� ��������
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

// 2. �������� ����������� ������� ��������� ������ � ������ ���������� � �����, � �� � �������.

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

// ����������� ������ ������ ����� ���� ���� � ����� �� ����� �, ���������� ������� main � ��� ����������� �������.
int main(){

    const int tree_size = 50;
    const int node_size = 10000;
    Node root[tree_size] = {};
    CreateForest(root, tree_size, node_size);
    cout << "Result :  " << Balancing_percentage(root, tree_size, node_size) << " %" << endl;
    cout << search(&root[0], 333) << endl;
    return 0;

}