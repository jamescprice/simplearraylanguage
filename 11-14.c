// C++ program to evaluate an expression tree
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
//https://www.geeksforgeeks.org/evaluation-of-expression-tree/
// Class to represent the nodes of syntax tree
class node
{
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x)
    {
        info = x;
    }
//    int array[3]= {111, 222, 333} ;
    int array[3]= { rand() % 5 , rand() % 100 , rand()  % 10000};
};



void printLeafNodes(node *root)
{
    // if node is null, return
    if (!root)
        return;
     
    // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->info << " ";
        return;
    }
 
    // if left child exists, check for leaf
    // recursively
             cout << root->info << " ";

    if (root->left)
       printLeafNodes(root->left);
         
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);
}


int * arsum ( int * m1, int * m2)
{
  int * arrayp;
  arrayp = (int *)malloc(sizeof(int) * 3 );

  printf("\nIN ARRAYSUM ");
  int i;
  printf("left "); for (i = 0; i < 3; i++){ printf("%d ", m1[i]); }
  printf("right "); for (i = 0; i < 3; i++){ printf("%d ", m2[i]); }
  for (i = 0; i < 3; i++){ arrayp[i] = m1[i]+m2[i]; }
  printf("arrayp: ");  cout << arrayp[0] << " " <<  arrayp[1] << " " << arrayp[2] <<  endl; 
  
    return arrayp;
}
int * arminus ( int * m1, int * m2)
{
  int * arraypm;
  arraypm = (int *)malloc(sizeof(int) * 3 );

  printf("\nIN ARRAYMINUS ");
  int i;
  printf("left "); for (i = 0; i < 3; i++){ printf("%d ", m1[i]); }
  printf("right "); for (i = 0; i < 3; i++){ printf("%d ", m2[i]); }
  for (i = 0; i < 3; i++){ arraypm[i] = m1[i]-m2[i]; }
  printf("arrayp: ");  cout << arraypm[0] << " " <<  arraypm[1] << " " << arraypm[2] <<  endl;

    return arraypm;
}


int * artimes ( int * m1, int * m2)
{
  int * arraypm;
  arraypm = (int *)malloc(sizeof(int) * 3 );

  printf("\nIN ARRAYTIMES ");
  int i;
  printf("left "); for (i = 0; i < 3; i++){ printf("%d ", m1[i]); }
  printf("right "); for (i = 0; i < 3; i++){ printf("%d ", m2[i]); }
  for (i = 0; i < 3; i++){ arraypm[i] = m1[i]*m2[i]; }
  printf("arrayp: ");  cout << arraypm[0] << " " <<  arraypm[1] << " " << arraypm[2] <<  endl;

    return arraypm;
}
int * ardivide ( int * m1, int * m2)
{
  int * arraypm;
  arraypm = (int *)malloc(sizeof(int) * 3 );

  printf("\nIN ARRAYDIVIDE");
  int i;
  printf("left "); for (i = 0; i < 3; i++){ printf("%d ", m1[i]); }
  printf("right "); for (i = 0; i < 3; i++){ printf("%d ", m2[i]); }
  for (i = 0; i < 3; i++){ arraypm[i] = m1[i]/m2[i]; }
  printf("arrayp: ");  cout << arraypm[0] << " " <<  arraypm[1] << " " << arraypm[2] <<  endl;

    return arraypm;
}




 
// Utility function to return the integer value
// of a given string
int toInt(string s)
{
    int num = 0;
         
    // Check if the integral value is
    // negative or not
    // If it is not negative, generate the number
    // normally
    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    // If it is negative, calculate the +ve number
    // first ignoring the sign and invert the
    // sign at the end
    else
    {
      for (int i=1; i<s.length(); i++)
        num = num*10 + (int(s[i])-48);
      num = num*-1;
    }
     
    return num;
}
 
// This function receives a node of the syntax tree
// and recursively evaluates it
int eval(node* root)
{
    // empty tree
    if (!root)
        return 0;
    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->info);
    // Evaluate left subtree
    int l_val = eval(root->left);
    // Evaluate right subtree
    int r_val = eval(root->right);
    // Check which operator to apply
    if (root->info=="+")
        return l_val+r_val;
    if (root->info=="-")
        return l_val-r_val;
    if (root->info=="*")
        return l_val*r_val;
    return l_val/r_val;
}




// This function receives a node of the syntax tree
// and recursively evaluates it
int fix(node* root)
{  
//cout << "in fix!" << endl;
    // empty tree
    if (!root)
        return 0;
    // leaf node i.e, an integer
    if (!root->left && !root->right){
     root->array[0] = toInt(root->info);
     root->array[1] = 2 * toInt(root->info);
     root->array[2] = 3 * toInt(root->info);

 //    cout << "in fix" << root->array[0] << root->array[1]  << root->array[2] <<  toInt(root->info) << endl;


        return toInt(root->info);
    }
    // Evaluate left subtree
    int l_val = fix(root->left);
    // Evaluate right subtree
    int r_val = fix(root->right);
    // Check which operator to apply
    if (root->info=="+")
        return l_val+r_val;
    if (root->info=="-")
        return l_val-r_val;
    if (root->info=="*")
        return l_val*r_val;
    return l_val/r_val;
}

int * eval2(node* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
////////////////////        return toInt(root->info);
      {
          int * arrayp;
          arrayp = (int *)malloc(sizeof(int) * 3 );

          arrayp[0] = root->array[0];
          arrayp[1] = root->array[1];
          arrayp[2] = root->array[2];
//        return toInt(root->info);
          return arrayp;
      }

    // Evaluate left subtree
           //   int l_val = eval(root->left);

       static int * larp;
       static int * rarp;
    
       larp = eval2(root->left);
    // Evaluate right subtree
            //  int r_val = eval(root->right);
        rarp = eval2(root->right);
  //    cout << rarp << "rarp" <<endl;
    // Check which operator to apply
    if (root->info=="+")
    {
/////      arsum(larp,rarp);
      return  arsum(eval2(root->left), eval2(root->right));
    //    return l_val+r_val;
    }
    if (root->info=="-") {
         return  arminus(eval2(root->left), eval2(root->right));

//        return l_val-r_val;
    }
    if (root->info=="*") {
       return  artimes(eval2(root->left), eval2(root->right));

//       return l_val*r_val;
 }
    return  ardivide(eval2(root->left), eval2(root->right));

//    return l_val/r_val;
}


//driver function to check the above program
int main()
{

    // create a syntax tree
/***    node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("+");
    root->right->left = new node("100");
    root->right->right = new node("20");
*/
        node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
    cout << fix(root) << endl; 
    printLeafNodes(root);
    cout << eval2(root);
//    cout << storearray[0] << storearray[1] << storearray[2] << endl;


    return 0;
}
