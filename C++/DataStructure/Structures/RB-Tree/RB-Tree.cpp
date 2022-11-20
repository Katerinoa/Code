#include <bits/stdc++.h>
using namespace std;
const static bool RED = 0;
const static bool BLACK = 1;

struct Node
{
    int val;
    bool color;
    Node *left, *right, *p; //左右孩子和父节点
    Node(const int &v, const bool &c = RED, Node *l = nullptr, Node *r = nullptr, Node *_p = nullptr) : val(v), color(c), left(l), right(r), p(_p) {}
};

struct RBTree
{
    Node *root;
    Node *nil;
    RBTree()
    {
        nil = new Node(-1, BLACK, nil, nil, nil);
        root = nil; // nil为外部辅助节点，为黑色
    }
    //左旋
    void left_rotate(Node *x)
    {
        /**将节点x左旋分为6步
         * 1 让x的右指针指向y的左孩子，以便于后面x成为y的左孩子
         * 2 让y的左孩子的父指针指向x，完成双向连接
         * 3 让y的父指针指向x的父结点
         * 4 让x的父结点的孩子指针指向y，完成双向连接
         * 5 让x的父结点指向y
         * 6 让y的左指针指向x，完成双向连接
         */
        Node *y = x->right; // y为x的右孩子
        x->right = y->left; // 1 让y的左孩子成为x的右孩子
        if (y->left != nil)
            y->left->p = x; // 2 如果y的左孩子不是nil，让y的左孩子的父节点成为x，完成双向连接
        y->p = x->p;        // 3 将x的父节点设置为y的父节点
        // 4 接下来让x的父节点指向y，有三种情况
        if (x->p == nil)
            root = y; // ① 如果x是根节点，那么将现在的y直接设置为根节点
        else if (x->p->left == x)
            x->p->left = y; // ② 如果x是父节点的左孩子，那么将y设置为父节点的左孩子
        else
            x->p->right = y; // ③ 如果x是父节点的右孩子，那么将y设置为父节点的右孩子
        x->p = y;            // 5 y成为x的父节点
        y->left = x;         // 6 x成为y的左孩子
    }
    //右旋
    void right_rotate(Node *x)
    {
        /**将节点x左旋分为6步
         * 其中1 2 6步是左旋操作的镜像
         * 3 4 5步与左旋相同
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
    //插入一个节点（不修复）
    Node *insert_bst(Node *&p, Node *&r, const int &v) // r为当前操作的节点，p为r的父节点
    {
        if (r == nil) //树为空
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
    //插入并修复（2*3种情况）
    void insert_fixup(const int &v)
    {
        Node *z = insert_bst(nil, root, v); //将新节点插入红黑树，并设为红色
        while (z->p->color == RED)          // z和z的父节点都是红节点
        {
            if (z->p->p->left == z->p) // 1 z的父节点是z的祖父节点的左孩子
            {
                // case1_1:z节点的父节点和叔叔节点都是红色
                if (z->p->p->right->color == RED)
                {
                    z->p->color = BLACK;           // z的父节点变为黑色
                    z->p->p->color = RED;          // z的祖父节点变成红色
                    z->p->p->right->color = BLACK; // z的叔叔节点变成黑色
                    z = z->p->p;                   //此时以z的祖父节点为根的树已经符合了红黑树的规则，但是z的祖父节点发生改变，因此将z的祖父节点视作新节点
                }
                else
                {
                    // case1_2:z节点的父节点是红色，叔叔节点没有或者是黑色，且z是父节点的右孩子
                    if (z->p->right == z)
                    {
                        z = z->p;       // z指向z的父节点
                        left_rotate(z); //左旋z节点（左旋后，z成为红色父节点的左孩子）
                    }
                    // case1_3:z节点的父节点是红色，叔叔节点没有或者是黑色，且z是父节点的左孩子
                    right_rotate(z->p->p); //右旋z的祖父节点
                    z->p->color = BLACK;   // z的父节点设为黑色
                    z->p->p->color = RED;  // z的祖父节点设为红色
                }
            }
            else // 2 z的父节点是z的祖父节点的右孩子（与1下的三种情况镜像对称）
            {
                // case 2_1 z节点的父节点和叔叔节点都是红色
                if (z->p->p->left->color == RED)
                {
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    z->p->p->left->color = BLACK;
                    z = z->p->p;
                }
                else
                {
                    // case2_2:z节点的父节点是红色，叔叔节点没有或者是黑色，且z是父节点的左孩子
                    if (z->p->left == z)
                    {
                        z = z->p;
                        right_rotate(z);
                    }
                    // case2_3:z节点的父节点是红色，叔叔节点没有或者是黑色，且z是父节点的左孩子
                    left_rotate(z->p->p);
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                }
            }
        }
        root->color = BLACK; //最后将根节点设为黑色
    }
};
