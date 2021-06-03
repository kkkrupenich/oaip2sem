#ifndef TREE_H
#define TREE_H
#include <QString>
#include <QVector>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>

struct Node
{
    int key;
    QString data;
    Node *left;
    Node *right;
    int height = 0;

    Node()
    {
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    QVector<Node*> answer;
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    void setBalance()
    {
        root = setBalance(root);
    }

    Node* setBalance(Node* p)
    {
        if(p != nullptr)
        {
            if(p->left != nullptr)
                p->left = setBalance(p->left);
            if(p->right != nullptr)
                p->right = setBalance(p->right);
            p = binary(p);
        }
        return binary(p);
    }

    Node* binary(Node* p)
    {
        if(!p) return nullptr;
        fixheight(p);
        if( bfactor(p)== 2 )
        {
            if( bfactor(p->right) < 0 )
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }

    Node* rotateleft(Node* p)
    {
        Node* q = p->right;
        p->right = q->left;
        q->left = p;
        fixheight(q);
        fixheight(p);
        return q;
    }

    Node* rotateright(Node* p)
    {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(q);
        fixheight(p);
        return q;
    }

    int height(Node *p)
    {
        return p?p->height:0;
    }

    void fixheight(Node *p)
    {
        int h1 = height(p->left);
        int h2 = height(p->right);
        p->height = (h1>h2?h1:h2) + 1;
    }

    int bfactor(Node *p)
    {
        int h1 = height(p->left);
        int h2 = height(p->right);
        return h2 - h1;
    }

    void push(int treeKey, QString treeData, Node** node)
    {
        if(!*node)
        {
            *node = new Node();
            (*node)->data = treeData;
            (*node)->key = treeKey;
        }
        else
        {
            if(treeKey < (*node)->key)
            {
                push(treeKey, treeData, &((*node)->left));
            }
            else if(treeKey > (*node)->key)
            {
                push(treeKey, treeData, &((*node)->right));
            }
        }
        setBalance();
    }

    QVector<Node*> removeSmth(int key)
    {
        answer.clear();
        in_order(root);
        for(int i = 0; i < answer.size(); i++)
            if(answer[i]->key == key)
                answer.removeAt(i);
        return answer;
    }

    /*void remove(int key)//doesnt work correctly
    {
        if(!root) return;
        Node* current = root;
        Node* parent = nullptr;
        while(current && current->key != key)
        {
            parent = current;
            if(key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        if(!current)
            return;

        if(current->left == nullptr)
        {
            if(parent && parent->left == current)
            {
                parent->left = current->right;
            }
            if(parent && parent->right == current)
            {
                parent->right = current->right;
            }
            if(current == root)
                root = current->right;
            delete current;
            binary(parent);
            return;
        }
        if(current->right == nullptr)
        {
            if(parent && parent->left == current)
            {
                parent->left = current->left;
            }
            if(parent && parent->right == current)
            {
                parent->right = current->left;
            }
            if(current == root)
                root = current->left;
            delete current;
            binary(parent);
            return;
        }
        if(!current->left && !current->right)
        {
            if(parent && parent->left == current)
            {
                parent->left = nullptr;
            }
            if(parent && parent->right == current)
            {
                parent->right = nullptr;
            }
            if(current == root)
            {
                delete current;
                delete root;
                root = current = nullptr;
                return;
            }
            delete current;
            binary(parent);
            return;
        }
    }*/

    QString find(int key, Node* root)
    {
        if(!root) return "-1";
        Node* current = root;
        while(current != nullptr)
        {
            if(key == current->key)
                return current->data;
            if(key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        delete current;
        return "-1";
    }

    void clear()
    {
        free(root);
    }

    void free(Node* tree)
    {
        if(!tree) return;
        free(tree->left);
        free(tree->right);
        delete tree;
        tree = nullptr;
    }

    Node* task()//my task
    {
        if(!root) return nullptr;
        answer.clear();
        in_order(root);

        int min = 1e9, max = 0;
        for(int i = 0; i < answer.size(); i++)
        {
            min = fmin(min, answer[i]->key);
            max = fmax(max, answer[i]->key);
        }
        double sred = (min + max)/2;
        sred = round(sred);
        qDebug() << min << ' ' << max << ' ' << sred;

        max = 1e9;
        int index = 0;
        for(int i = 0; i < answer.size(); i++)
        {
            int temp = answer[i]->key - sred;
            if(temp < 0)
                temp = sred - answer[i]->key;
            if(temp < max)
            {
                max = temp;
                index = i;
            }
        }
        return answer[index];
    }

    int task(char c) //your task
    {
        if(!root) return 0;
        answer.clear();
        in_order(root);

        int count = 0;
        for(int i = 0; i < answer.size(); i++)
        {
            QString temp = answer[i]->data;
            if(temp[0] == c)
                count++;
        }
        return count;
    }

    void print()
    {
        answer.clear();
        pre_order(root);
        in_order(root);
        post_order(root);
    }

    void pre_order(Node* root)
    {
        if(!root) return;
        answer.append(root);
        pre_order(root->left);
        pre_order(root->right);
    }

    void in_order(Node* root)
    {
        if(!root) return;
        in_order(root->left);
        answer.append(root);
        in_order(root->right);
    }

    void post_order(Node* root)
    {
        if(!root) return;
        post_order(root->left);
        post_order(root->right);
        answer.append(root);
    }
};

#endif // TREE_H
