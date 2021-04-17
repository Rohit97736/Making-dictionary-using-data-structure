#include <iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<fstream>

using namespace std;

class Node
{
   string word;
   Node *left,*right;
   int hei;

public:

  Node(string word)
  {
    this->word=word;
    left=right=NULL;
    hei=1;
  }

 void print()
 {
    cout<<endl<<setw(10)<<word<<setw(10)<<"\n";
 }

 friend class Dictionary;

};

class Dictionary
{
   Node *root;

public:
   Dictionary()
    {
      root=NULL;
    }
 int max(int,int);
 int hei(Node*);
 Node *insert(Node *rnode,string word);
 void insertIn(string word);
 Node *rightRotate(Node *);
 Node *leftRotate(Node *);
 int getbalance(Node*);
 void inorder();
 void inorderRec(Node *);
 void search(string);
 Node *search(Node *,string);
 void edits(const string& , Node *  );
 bool compare(std::pair<int,string> ,std::pair<int,string> );
 int min(int , int , int );
 int editDistance(string , string , int, int );
 int min(int ,int );

};

 int Dictionary::max(int a,int b)     //returns max of two numbers
{
 return (a>b)?a:b;
}

 int Dictionary::hei(Node *nnode)  //returns the height of subtree
{
 if(nnode==NULL) return 0;
 else return nnode->hei;
}

 int Dictionary::getbalance(Node *n)  //returns the difference in height of subtrees
{
 if(n==NULL) return 0;
 else return (hei(n->left)-hei(n->right));
}

Node* Dictionary::rightRotate(Node *r)  //to rotate right about a node and update height accordingly
{
 Node *x=r->left;
 Node *T=x->right;

 x->right=r;
 r->left=T;

 r->hei=max(hei(r->left),hei(r->right))+1;
 x->hei=max(hei(x->left),hei(x->right))+1;
 return x;
}

Node* Dictionary::leftRotate(Node *l)   //to rotate left about a node and update height accordingly
{
 Node *x=l->right;
 Node *T=x->left;

 x->left=l;
 l->right=T;

 l->hei=max(hei(l->left),hei(l->right))+1;
 x->hei=max(hei(x->left),hei(x->right))+1;

 return x;
}

Node* Dictionary::insert(Node *rnode,string word)  //to insert a node in AVL tree
{
  if(rnode==NULL) return new Node(word);

  if(word.compare(rnode->word)<=0) rnode->left=insert(rnode->left,word);
  else if (word.compare(rnode->word)>0) rnode->right=insert(rnode->right,word);
  else return rnode;

  rnode->hei=1+max(hei(rnode->left),hei(rnode->right));

  int balance=getbalance(rnode);

  if(balance>1 && (word.compare(rnode->left->word)<=0))
  return rightRotate(rnode);

  if(balance<-1 && (word.compare(rnode->right->word)>0))
  return leftRotate(rnode);

  if(balance>1 && (word.compare(rnode->left->word)>0))
  {
    rnode->left=leftRotate(rnode->left);
    return rightRotate(rnode);
  }

   if(balance<-1 &&(word.compare(rnode->right->word)<=0))
  {
    rnode->right=rightRotate(rnode->right);
    return leftRotate(rnode);
  }

  return rnode;

}

void Dictionary::inorder()
 {
   inorderRec(root);
 }


 void Dictionary::inorderRec(Node *n)  //function to  do inorder traversal of a tree
{
  if(n)
 {
  inorderRec(n->left);
  n->print();
  inorderRec(n->right);
 }
}

 void Dictionary::insertIn(string word)
{
 root=insert(root,word);
}

Node * Dictionary::search(Node *rnode,string rword) //function to search in AVL/BST tree
{
  if (rnode == NULL || rnode->word ==rword)
       return rnode;

  if (rnode->word < rword)
       return search(rnode->right, rword);

    return search(rnode->left, rword);
}

int Dictionary:: min(int x,int y)                 //returns minimum of two values
 {
   if(x>y) return y;
   else return x;
 }

 int Dictionary:: min(int x, int y, int z)       //returns minimum of three values
{
    return min(min(x, y), z);
}

int Dictionary:: editDistance(string str1, string str2, int m, int n) //Dynamic programming code to find edit distance between two strings
{

    int dp[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
      for (int j=0; j<=n; j++)
        {
          if (i==0) dp[i][j] = j;

          else if (j==0) dp[i][j] = i;

          else if (str1[i-1] == str2[j-1])
             dp[i][j] = dp[i-1][j-1];

          else dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
  return dp[m][n];
}

void Dictionary::edits(const string& rword, Node *rnode)  //function to suggest appropriate word if wrong word is enterd by the user
 {
   int response;
   queue<Node*> Q;
   int min_edit,temp_dist; string match;
   int m=rword.size();

   if(rnode==NULL) return;

   else
   { Q.push(rnode);
     int s=rnode->word.size();
     min_edit=editDistance(rword,rnode->word,m,s);
     match=rnode->word;
   }

   while(!Q.empty())
   {
     Node *P=Q.front();
     int n= P->word.size();
     temp_dist=editDistance(rword,P->word,m,n);
     if(temp_dist<min_edit) { min_edit=temp_dist; match=P->word; }
     Q.pop();


        if(P->left!=NULL) Q.push(P->left);
     if(P->right!=NULL) Q.push(P->right);
   }

   cout<<".\n DID YOU MEAN:\t"<<match<<endl;
   cout<<".\nIF YES ENTER 1 ELSE 0:\t";
   cin>>response;

   if(response==1)

     search(match);

   else

     cout<<".\n\nSorry not be found.\n";

  }

  void Dictionary::search(string rword)
{

  Node *index=search (root ,rword);

  if(index!=NULL)  index->print();

  else
   {
     edits( rword , root );
   }

   return ;
}

int main()
{

  Dictionary dict;
  vector<string> result;

     dict.insertIn("Head Ofiice");
    dict.insertIn("gtropy");
    dict.insertIn("Above");
    dict.insertIn("indian");
    
   dict.insertIn("bank");
   dict.insertIn("sarvodaya");
   dict.insertIn("enclave");
   dict.insertIn("Sri");
   dict.insertIn("Aurobindo");
   dict.insertIn("Marg");
   dict.insertIn("New");
   dict.insertIn("Delhi");

   dict.insertIn("aardvarks");
   dict.insertIn("aardvark");
   dict.insertIn("aahingy");


   cout<<".DICTIONARY:\n";
   dict.inorder();

  string search_word;
  int response;
  cout<<".\n\nEnter any word u want to search:\t";
  cin>>search_word;
  cout<<".\n";
  dict.search(search_word);


 return 0;
}

