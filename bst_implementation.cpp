//@shubhamgupta

#include "iostream"
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;


    }


};



struct node* add_node(node *head,int d){

    if(head==NULL){
        cout<<"node added successfully!"<<endl;
        return new node(d);


    }

    else if(d>=head->data){
        head->right=add_node(head->right,d);


    }

    else{

        head->left=add_node(head->left,d);
    }

    return head;


}

struct node *min_node(struct node *head) {
    struct node *current = head;

    while (current && current->left != NULL) {
        current = current->left;

    }

    return current;
}

struct node* delete_node(node *head,int d){

    if(head==NULL){

        return head;
    }

    else if(d>head->data){

        head->right=delete_node(head->right,d);
    }

    else if(d<head->data){

        head->left=delete_node(head->left,d);
    }

    else{

        if (head->left == NULL) {

            struct node *temp = head->right;
            free(head);
            return temp;

        }

        else if (head->right == NULL) {
            struct node *temp = head->left;
            free(head);
            return temp;
        }

        struct node *temp = min_node(head->right);

        head->data = temp->data;

        head->right = delete_node(head->right, temp->data);
        cout<<"node deleted successfully!"<<endl;



    }

    return head;



}

void print_tree(node *head){

    if(!head){
        return;
    }

    print_tree(head->left);
    cout<<head->data<<endl;
    print_tree(head->right);


}

bool search_node(node *head, int d){

    if(head==NULL){

        return false;

    }

    else if(head->data==d){

        return true;
    }

    else if(d>head->data){

        return search_node(head->right,d);
    }

    else{

        return search_node(head->left,d);
    }



}


int main(){
    node *root=NULL;
    int choice=-1;
    cout<<"Binary Seach Tree";


    while(choice!=0){

        cout<<"Enter your choice"<<endl;
        cout<<"1: To add a node"<<endl;
        cout<<"2: To delete a node"<<endl;
        cout<<"3: To print the tree inorder"<<endl;
        cout<<"4: To find a node in the tree"<<endl;
        cout<<"0: To exit from the program"<<endl;

        cin>>choice;

        switch (choice) {

            case 1:{

                cout<<"Enter the node to insert:"<<endl;
                int data;
                cin>>data;
                root=add_node(root,data);
                break;

            }

            case 2:{
                cout<<"Enter the node to delete:"<<endl;
                int data;
                cin>>data;
                root=delete_node(root,data);
                break;


            }

            case 3:{
                print_tree(root);
                break;


            }

            case 4:{
                cout<<"Enter the node to search:"<<endl;
                int data;
                cin>>data;
                if(search_node(root,data)){

                    cout<<"node found!"<<endl;
                }

                else{

                    cout<<"node not found!"<<endl;
                }
                break;


            }

            case 0:{

                exit(0);
            }

            default:{

                cout<<"Invalid choice! Please enter again:"<<endl;
                break;
            }


        }


    }


}

