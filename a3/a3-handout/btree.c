/* Name: Supanut Boat
 * ID: 5881050
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

Node *recurInsert(Node *tre , int val){

    if(tre == NULL){
        tre = malloc(sizeof(Node));
        tre->left = NULL;
        tre->right = NULL;
        tre->data = val;
        return tre;
    }
    if(val < (tre)->data){
        (tre)->left = recurInsert((tre)->left,val);
    }
    else if(val >= (tre)->data){
        (tre)->right = recurInsert((tre)->right,val);
    }
    return tre;
}

void insert(Node **tree, int val) {
    // IMPLEMENT
    if(*tree == NULL){
        *tree = malloc(sizeof(Node));
        (*tree)->data = val;
        (*tree)->right = NULL;
        (*tree)->left = NULL;
        return;
    }
    if(val < (*tree)->data){
        (*tree)->left = recurInsert((*tree)->left,val);
    }else if(val >= (*tree)->data){
        (*tree)->right = recurInsert((*tree)->right,val);
    }


}

void recurePrint(Node *tre,int level){
    int temp = level;
    int space = 0;
    int stick = 0;
    if(temp>=1){
        stick++;
        temp--;
    }
    space = temp*2;


    if(tre->left == NULL && tre->right == NULL){
        for(int i=0;i<space;i++){
            printf("%s"," ");
        }
        if(stick>0){
            printf("%s","|-");
        }
        printf("%d\n",tre->data);
        return;
    } else{
        //print root

        for(int i=0;i<space;i++){
            printf("%s"," ");
        }
        if(stick>0){
            printf("%s","|-");
        }

        printf("%d\n",tre->data);

        //go left
        level++;
        if(tre->left != NULL){
            recurePrint(tre->left,level);
        }

        //go right
        if(tre->right != NULL){
            recurePrint(tre->right,level);
        }

        return;
    }

}

void print(Node *tree) {
    // IMPLEMENT
    recurePrint(tree,0);

}

void recureDelete(Node *tre){

    if(tre->left == NULL && tre->right == NULL){
        //free current node (deepest node)
        free(tre);
        return;
    } else{

        //go left
        if(tre->left != NULL){
            recureDelete(tre->left);
        }

        //go right
        if(tre->right != NULL){
            recureDelete(tre->right);
        }
        //free current node
        free(tre);
        return;
    }

}

void delete(Node *tree) {
    // IMPLEMENT
    recureDelete(tree);
}

Node *recureFind(Node *tre,int val){

    if(tre->left == NULL && tre->right == NULL){
        //Check if this node's data == val
        if(tre->data == val){
            return tre;
        }
        return NULL;
    } else{

        //Check val on current node
        if(tre->data == val){
            return tre;
        }

        if(val < tre->data && tre->left != NULL){
            //go left
            return recureFind(tre->left, val);

        } else if(val >= tre->data && tre->right != NULL){
            //go right
            return recureFind(tre->right, val);

        }

        return NULL;
    }

}

Node *lookup(Node ** tree, int val) {
    // IMPLEMENT
    return recureFind(*tree,val);
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{

    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
