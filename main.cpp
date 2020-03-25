#include <iostream>

class Tree
{
public:

    Tree  *father,*left_son, *right_brother;long long int data;
    Tree( Tree *father,Tree *left_son,Tree *right_brother,long long int data)
        :father(father),left_son(left_son),right_brother(right_brother),data(data)
    {}
    Tree(long long int data)
        :left_son(nullptr),right_brother(nullptr),data(data){}
};

class TreeManaging
{
public:
    Tree* root;

    void preOrder(Tree *t);
    TreeManaging(){
        root = new Tree(nullptr,nullptr,nullptr,0);

    }
    void mainLoop()
    {
        std::ios::sync_with_stdio(false);
        Tree *positionInTree = root;
        long long int sets,howManyNumbers,value;

        std::cin>>sets;
        for(long long int i=0; i<sets ;i++){
            positionInTree = root;
            std::cin>>howManyNumbers;
            for (int j = 0; j < howManyNumbers; j++)
            {
                std::cin>>value;

                if(positionInTree->left_son)
                {
                    positionInTree = positionInTree->left_son;
                    while(positionInTree->data !=value && positionInTree->right_brother)
                        positionInTree = positionInTree->right_brother;

                    if(positionInTree->data == value)
                        continue;
                    if(!positionInTree->right_brother)
                    {
                        positionInTree->right_brother = new Tree(value);
                        positionInTree->right_brother->father = positionInTree->father;
                        positionInTree = positionInTree->right_brother;
                    }
                }
                else//if(nie ma syna.)
                {
                    positionInTree->left_son = new Tree(value);
                    positionInTree->left_son->father = positionInTree;
                    positionInTree = positionInTree->left_son;

                }
            }
        }

    }


};

int main()
{
    TreeManaging *firstTree = new TreeManaging();
    firstTree->mainLoop();
    firstTree->preOrder(firstTree->root);


    return 0;


}


void TreeManaging::preOrder(Tree *t)
{
    std::ios::sync_with_stdio(false);

    if(t != root)
        std::cout<<t->data<<" ";


    if(t->left_son)
        preOrder(t->left_son);

    if(t->right_brother)
        preOrder(t->right_brother);



}
