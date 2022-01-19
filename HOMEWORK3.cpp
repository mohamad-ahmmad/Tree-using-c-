#include"tree.h"

int main()
{
    int choice=0;
    MyBinaryTree Tree;
    while (1)
    {
        print_menu();
        cout << "Choose a service :";
        cin >> choice;
        if (choice == 1) {
            
          
                int num_of_nodes;
                cout << "How Many Nodes Would You Like To Insert:";
                cin >> num_of_nodes;
                int data;
                for (int j = 1;j <= num_of_nodes; j++) {
                    cout << "The Value of Node Number (" << j << ") :";
                    cin >> data;
                    Tree.set_root(Tree.insert(Tree.creat_node(data)));
                }

         
            
            system("PAUSE");
            system("CLS");
        }
        else if (choice == 2)
        {
            int data;
            cout << "Insert the Data of The Node :";
            cin >> data;
            NODE* ptr = new NODE;
            ptr = Tree.creat_node(data);
            
            if(!(ptr ==NULL))
            Tree.set_root(Tree.insert(ptr));

            system("PAUSE");
            system("CLS");
        }
        else if (choice == 3)
        {
            Tree.print_INorder();
            cout << "\n";
            system("PAUSE");
            system("CLS");
        }
        else if (choice == 4) {
            int R1, R2;
            
            cout << "The Value Range Between (Value 1 < Value 2)." << endl;
            cout << "The First Value:";
            cin >> R1;cout << "\n";
            cout << "The Second Value:";
                cin >> R2;cout << "\n";

                cout << "Values Between " << R1 << " And " << R2 << " :";
                Tree.print_inrange(R1, R2);
                cout << endl;
                system("PAUSE");
                system("CLS");
        }
        else if (choice == 5) {
            if (Tree.get_root() == NULL) {
                cout << "Empty Tree." << endl;
            }

        else if (Tree.isBalanced() == true) {
                cout << "The Tree is Balanced" << endl;
           }
            else  {
                cout << "The Tree is Not Balanced" << endl;
            }

            system("PAUSE");
            system("CLS");

        }
        else if (choice == 6) {
            int sum;
            cout << "The Sum of The Two Children:";
            cin >> sum;

            Tree.PrintSumNodesK(sum);
            cout << endl;
            system("PAUSE");
            system("CLS");
        }
        else if (choice == 7) {
            int lv1, lv2;
            cout << "Insert The Two Levels (Level 1 < Level 2)." << endl;
            cout << "Level One:";cin >> lv1;cout << endl;
            cout << "Level Two:";cin >> lv2;cout << endl;

            Tree.print_lv1_to_lv2(lv1 , lv2);
            
            system("PAUSE");
            system("CLS");
        }
        else if (choice == 8) {
            int data;
            cout << "The Data of The Node:";
            cin >> data;

            cout << "The Height of The Node :" << Tree.hight(data) << endl;

            system("PAUSE");
            system("CLS");
        }
        else if (choice == 9) {
            
            return 0;
        }
        else {
            cout << "The Number is Not in The List.\n";
            system("PAUSE");
            system("CLS");
        }

    }
    return 0;
}
