#include <bits/stdc++.h>
using namespace std;
const static bool RED = 0;
const static bool BLACK = 1;

struct Node
{
    int val;
    bool color;
    Node *left, *right, *p; //���Һ��Ӻ͸��ڵ�
    Node(const int &v, const bool &c = RED, Node *l = nullptr, Node *r = nullptr, Node *_p = nullptr) : val(v), color(c), left(l), right(r), p(_p) {}
};

struct RBTree
{
    Node *root;
    Node *nil;
    RBTree()
    {
        nil = new Node(-1, BLACK, nil, nil, nil);
        root = nil; // nilΪ�ⲿ�����ڵ㣬Ϊ��ɫ
    }
    //����
    void left_rotate(Node *x)
    {
        /**���ڵ�x������Ϊ6��
         * 1 ��x����ָ��ָ��y�����ӣ��Ա��ں���x��Ϊy������
         * 2 ��y�����ӵĸ�ָ��ָ��x�����˫������
         * 3 ��y�ĸ�ָ��ָ��x�ĸ����
         * 4 ��x�ĸ����ĺ���ָ��ָ��y�����˫������
         * 5 ��x�ĸ����ָ��y
         * 6 ��y����ָ��ָ��x�����˫������
         */
        Node *y = x->right; // yΪx���Һ���
        x->right = y->left; // 1 ��y�����ӳ�Ϊx���Һ���
        if (y->left != nil)
            y->left->p = x; // 2 ���y�����Ӳ���nil����y�����ӵĸ��ڵ��Ϊx�����˫������
        y->p = x->p;        // 3 ��x�ĸ��ڵ�����Ϊy�ĸ��ڵ�
        // 4 ��������x�ĸ��ڵ�ָ��y�����������
        if (x->p == nil)
            root = y; // �� ���x�Ǹ��ڵ㣬��ô�����ڵ�yֱ������Ϊ���ڵ�
        else if (x->p->left == x)
            x->p->left = y; // �� ���x�Ǹ��ڵ�����ӣ���ô��y����Ϊ���ڵ������
        else
            x->p->right = y; // �� ���x�Ǹ��ڵ���Һ��ӣ���ô��y����Ϊ���ڵ���Һ���
        x->p = y;            // 5 y��Ϊx�ĸ��ڵ�
        y->left = x;         // 6 x��Ϊy������
    }
    //����
    void right_rotate(Node *x)
    {
        /**���ڵ�x������Ϊ6��
         * ����1 2 6�������������ľ���
         * 3 4 5����������ͬ
         */
        Node *y = x->left;
        x->left = y->right;
        if (y->right != nil)
            y->right->p = x;
        y->p = x->p;
        if (x->p == nil)
            root = y;
        else if (x->p->left == x)
            x->p->left = y;
        else
            x->p->right = y;
        x->p = y;
        y->right = x;
    }
    //����һ���ڵ㣨���޸���
    Node *insert_bst(Node *&p, Node *&r, const int &v) // rΪ��ǰ�����Ľڵ㣬pΪr�ĸ��ڵ�
    {
        if (r == nil) //��Ϊ��
        {
            r = new Node(v, RED, nil, nil, p);
            if (p == nil)
                root = r;
            if (v > p->val)
                p->right = r;
            else
                p->left = r;
        }
        else
        {
            if (v < r->val)
                return insert_bst(r, r->left, v);
            else
                return insert_bst(r, r->left, v);
        }
        return r;
    }
    //���벢�޸���2*3�������
    void insert_fixup(const int &v)
    {
        Node *z = insert_bst(nil, root, v); //���½ڵ��������������Ϊ��ɫ
        while (z->p->color == RED)          // z��z�ĸ��ڵ㶼�Ǻ�ڵ�
        {
            if (z->p->p->left == z->p) // 1 z�ĸ��ڵ���z���游�ڵ������
            {
                // case1_1:z�ڵ�ĸ��ڵ������ڵ㶼�Ǻ�ɫ
                if (z->p->p->right->color == RED)
                {
                    z->p->color = BLACK;           // z�ĸ��ڵ��Ϊ��ɫ
                    z->p->p->color = RED;          // z���游�ڵ��ɺ�ɫ
                    z->p->p->right->color = BLACK; // z������ڵ��ɺ�ɫ
                    z = z->p->p;                   //��ʱ��z���游�ڵ�Ϊ�������Ѿ������˺�����Ĺ��򣬵���z���游�ڵ㷢���ı䣬��˽�z���游�ڵ������½ڵ�
                }
                else
                {
                    // case1_2:z�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ�û�л����Ǻ�ɫ����z�Ǹ��ڵ���Һ���
                    if (z->p->right == z)
                    {
                        z = z->p;       // zָ��z�ĸ��ڵ�
                        left_rotate(z); //����z�ڵ㣨������z��Ϊ��ɫ���ڵ�����ӣ�
                    }
                    // case1_3:z�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ�û�л����Ǻ�ɫ����z�Ǹ��ڵ������
                    right_rotate(z->p->p); //����z���游�ڵ�
                    z->p->color = BLACK;   // z�ĸ��ڵ���Ϊ��ɫ
                    z->p->p->color = RED;  // z���游�ڵ���Ϊ��ɫ
                }
            }
            else // 2 z�ĸ��ڵ���z���游�ڵ���Һ��ӣ���1�µ������������Գƣ�
            {
                // case 2_1 z�ڵ�ĸ��ڵ������ڵ㶼�Ǻ�ɫ
                if (z->p->p->left->color == RED)
                {
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    z->p->p->left->color = BLACK;
                    z = z->p->p;
                }
                else
                {
                    // case2_2:z�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ�û�л����Ǻ�ɫ����z�Ǹ��ڵ������
                    if (z->p->left == z)
                    {
                        z = z->p;
                        right_rotate(z);
                    }
                    // case2_3:z�ڵ�ĸ��ڵ��Ǻ�ɫ������ڵ�û�л����Ǻ�ɫ����z�Ǹ��ڵ������
                    left_rotate(z->p->p);
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                }
            }
        }
        root->color = BLACK; //��󽫸��ڵ���Ϊ��ɫ
    }
};
