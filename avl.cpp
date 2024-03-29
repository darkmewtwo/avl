#include<iostream>

#include <ostream>
#include <fstream>

#include"avl_head.h"
int level =0;
int h=0;
Elem *stemp=new Elem;
using namespace std;


void updateHeight(Elem*& cur)
{
    Elem *temp=new Elem;
    int l=1;
    temp=cur;
    _root->height=0;
    if(temp->left!=nullptr)
    {
       temp->left->height=temp->height+l;
       updateHeight(temp->left);
    }
      // cout<<'\t'<<temp->key<<'\t'<<"up hei "<<temp->height<<'\t'<<'\n';
   if(temp->right!=nullptr)
   {
      temp->right->height=temp->height+l;
      updateHeight(temp->right);
   }
      //cout<<'\t'<<temp->key<<'\t'<<"up hei "<<temp->height<<'\t'<<'\n';     
}


void printTree(std::ostream& out, int level, Elem *p)
{
    Elem *temp=new Elem;
    temp=p;
    //cout<<"hell on";
    //out<<"helltree print ";
   if(temp->left!=nullptr)
       printTree(out,level,temp->left);
   if(temp->height==0)
       cout<<"(root) -> ";
   out<<"key "<<temp->key<<'\t'<<"height "<<temp->height<<'\t'<<"data "<<temp->data<<'\n';
   if(temp->right!=nullptr)
       printTree(out,level,temp->right);
  // cout<<"done";
   
   
}


void doubleRotateLeft(Elem *& node)
{
    
    Elem *t1 = new Elem;
    Elem *temp=new Elem;
   // cout<<"here"<<stemp->key<<'\n'<<_root->key<<'\n';
    if(stemp->key==_root->key && stemp->right==nullptr)
    {
     //   cout<<"checking if root";
        t1=stemp;
    }
        else
        temp=stemp->left;
    //cout<<"temp   \n"<<temp->key;
    node->right=temp;
    temp->left=nullptr;
    temp->rightThread=true;
    node->rightThread=false;
    //cout<<temp->key<<'\n';
    if(stemp->key==_root->key && stemp->right== nullptr)
    {
      //  cout<<"root che";
        int k=t1->key;
        int d= t1->data;
     //_root->key=node->key;
     free(_root);
     _root=node;
     temp->key=k;
     temp->data=d;
    // cout<<'\t'<<temp->key;
     _root->right=temp;
     _root->left=node->left;
    }
     else
        stemp->left=node;
     //cout<<"double checking"<<_root->key<<_root->right->key<<_root->left->key;
     updateHeight(_root);

 //   printTree(cout,level,_root);
    //cout<<_root->key;
    cout<<"balanced continue entering \n";
    
}


void doubleRotateRight(Elem *& node)
{
    Elem *t1 = new Elem;
    Elem *temp=new Elem;
    //cout<<"here"<<stemp->key<<'\n'<<_root->key<<'\n';
    if(stemp->key==_root->key && stemp->left== nullptr)
    {
      //  cout<<"checking if root";
        t1=stemp;
    }
        else
        temp=stemp->right;
    //cout<<"temp   \n"<<temp->key;
    node->left=temp;
    temp->right=nullptr;
    temp->rightThread=true;
    node->rightThread=false;
   // cout<<temp->key<<'\n';
    if(stemp->key==_root->key && stemp->left == nullptr)
    {
     //   cout<<"root che";
        int k=t1->key;
        int d= t1->data;
     //_root->key=node->key;
     free(_root);
     _root=node;
     temp->key=k;
     temp->data=d;
     //cout<<'\t'<<temp->key;
     _root->left=temp;
     _root->right=node->right;
    }
     else
        stemp->right=node;
     //cout<<"double checking"<<_root->key<<_root->right->key<<_root->left->key;
     updateHeight(_root);

  //  printTree(cout,level,_root);
    //cout<<_root->key;
   // cout<<"balanced";
    
}


void rotateRight(Elem *& node)
{   
    int d;
    //cout<<"root"<<stemp->key;
    Elem *temp=new Elem;
    //cout<<node->key;
    temp=node->right;
    //cout<<"rR  "<<temp->key;
    node->left=temp;
    d=node->data;
    node->data=temp->data;
    temp->data=d;
    node->key+=temp->key;
    temp->key=node->key-temp->key;
    node->key=node->key-temp->key;
    node->right=nullptr;
  //  temp->left=node;
   // stemp->left->left=node;
    //stemp->left->key=temp->key;
    //stemp->left->right=nullptr;
    //cout<<'\n'<<node->key<<'\t'<<node->left->key;
    doubleRotateLeft(node);
   // printTree(cout,level,stemp);
    
}

void rotateLeft(Elem *& node)
{
    int d;
//      cout<<"root"<<stemp->key;
    Elem *temp=new Elem;
  //  cout<<node->key;
    temp=node->left;
  //  cout<<"rL  "<<temp->key;
    node->right=temp;
      d=node->data;
    node->data=temp->data;
    temp->data=d;
    node->key+=temp->key;
    temp->key=node->key-temp->key;
    node->key=node->key-temp->key;
    node->left=nullptr;
  //  temp->left=node;
   // stemp->left->left=node;
    //stemp->left->key=temp->key;
    //stemp->left->right=nullptr;
   // cout<<'\n'<<node->key<<'\t'<<node->right->key;
    doubleRotateRight(node);
   // printTree(cout,level,stemp);
}


void avlrotate(Elem *&temp,Elem *&cur)
{
    //char r;
    int l=0,r=0;
    if(temp->left==cur)
        //r='l';
        l=1;
    if(temp->right==cur)
        //r='r';
        l=2;
    if(cur->left!=nullptr)
        l=10*l+1;
    else if(cur->right!=nullptr)
        l=10*l+2;
    if(l==11)
    {
        cout<<"LL rotation\n";
        doubleRotateLeft(cur);
    }    //void doubleRotateLeft(Elem *& node);
    else if(l==22)
    {
        cout<<"RR rotation\n";
        doubleRotateRight(cur);
    }    //void doubleRotateRight(Elem *& node);
    else if(l==12)
    { 
        cout<<"LR rotation\n";
        rotateRight(cur);
    } 
    else if(l==21)
    {
        cout<<"RL rotation\n";
        rotateLeft(cur);
    }
}





int height(Elem *&node)
{
    //h=0;
    Elem *temp=new Elem;
    temp=node;
   // cout<<'\n'<<node->key<<'\t'<<node->height;
    //cout<<"hell on";
    //out<<"helltree print ";
   if(temp->left!=nullptr)
   //{   
       height(temp->left);
        if(h<temp->height)
       h=temp->height;
     //  cout<<"ver aga"<<temp->height<<'\t';
   //cout<<"ver"<<h;
   //cout<<temp->key<<'\t'<<"hei "<<temp->height<<'\t';
   if(temp->right!=nullptr)
   //{ 
       height(temp->right);
        if(h<temp->height)
        h=temp->height;
        
   //cout<<"reutrm value \t"<<h;
   return h;
}






int balanceFactor(Elem *&cur)
{
    int bf,d=0,d1=0;
   // cout<<"erwfers";
    if(cur->left!=nullptr)
     d=height(cur->left);
    h=0;
   // cout<<"reaching here %d\n"<<cur->key<<cur->height;
    if(cur->right!=nullptr){
     //   cout<<"going inside";
     d1=height(cur->right);}
    //cout<<"\n balfact"<<cur->key<<'\t'<<d<<'\t'<<d1;
   if(cur->left==nullptr){
      // cout<<"hell sode";
       bf=cur->height-d1;}
    else if(cur->right==nullptr)
       bf=d-cur->height;
    else
    bf=(d - cur->height)-(d1-cur->height);
  //  cout<<'\t'<<bf<<'\t';
    return bf;
    //return 0;
}



















void balance(Elem*& cur, const KEY &key)
{
   // int bal;
    Elem *s;
    Elem *temp;
    //cout<<key;
    //cout<<"for bala\n"<<cur->key;
  //  cout<<"hrewew";
    int bal=balanceFactor(cur);
 //cout<<"bal function "<<bal<<'\n';
  //temp=cur;
  //cur=cur->left;
 // cout<<temp->key;
  //cout<<"sdfbr";
  
 if(abs(bal)>=2)
     //cout<<"ss";
  {
      stemp=cur;
   //    cout<<"in here";
       while(abs(bal)>=2)
        {
     //       cout<<"checcking  ";
            temp=cur;
           if(key < temp->key)
            {
                cur=cur->left;
               bal = balanceFactor(cur);
            }
           else if(key >=temp->key)
            {
       //         cout<<cur->key;
         //       cout<<"balance 2nd if";
                cur=cur->right;
                bal=balanceFactor(cur);
            }
        } 
  //   bal =1;
        // cout<<'\t'<<temp->key<<'\t'<<cur->key;
         if(stemp->key>temp->key)
         {  
          //   cout<<"inside here1";
             while(stemp->left->key!=temp->key)
                 stemp=stemp->left;
        }
        if(stemp->key<temp->key)
         {  
            // cout<<"inside here2";
             while(stemp->right->key!=temp->key)
                 stemp=stemp->right;
        }
        //if(ste
        //cout<<stemp->key;
        avlrotate(temp,cur);  
       // cout<<"back here";
    }
       
   // cout<<"out of if";
//   return 0; 
    
}















bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft)
{   
    //cout<<"beg of inser \n";
    int levelt=0;
   Elem *t1=new Elem; 
   Elem *temp=new Elem;
   Elem *btemp=new Elem;
   Elem *node=new Elem;
   temp=root; 
   while(temp!=nullptr)
   {
      //  cout<<"here  "<<level<<'\n';
       levelt+=1; 
       btemp=temp;
       if(temp->key >key)
           temp=temp->left;
       else if(temp->key < key)
           temp=temp->right;
       
    }
    //cout<<"here";
    node->data=data;
    node->key=key;
    node->left = nullptr;
    node->right = nullptr;
    node->rightThread =false;
   // node->height=1;
    if(_root==nullptr)
    {
        //cout<<"here\t"<<&_root<<'\t';
        _root=node;
        _root->height=0;
        //cout<<_root<<'\t';
        //level =0;
    }
        else if(btemp->key >= key) //left tree
    {
        btemp->rightThread=false;
        btemp->left=node;
        node->rightThread=true;
      //  cout<<"height of recent paren\t     "<<btemp->height;
        node->height=1+btemp->height;
        //cout<<'\t'<<_root->key<<node->key<<"height of new \t"<<node->height<<'\n';
        t1=_root;
        balance(t1,node->key);
       // balanceFactor(btemp);
        
    }
    else if(btemp->key < key)
    {
        btemp->rightThread=false;
        btemp->right=node;
        node->rightThread=true;
     //   cout<<"height of recent paren\t     "<<btemp->height;
        node->height=1+btemp->height;
        t1=_root;
        balance(t1,node->key);
       // cout<<"inseer";
        
    }

    //cout<<"\nchecking"<<btemp->left<<'\t'<<btemp->right<<'\t'<<node;
    if(levelt>level)
        level=levelt;
   // cout<<'\t'<<levelt;
    //cout<<"addded     \n"<<level<<'\n';
    return true;
}


bool findkey(int k) //to find the node with key to delete
{   
    int f=0;
    Elem *temp1=new Elem;
    Elem *temp= new Elem;
    temp=_root;
    while(temp->key!=k)
    {
        if(temp->key>k)
        {
            f=1;
            temp1=temp;
            temp=temp->left;
        }
        else if(temp->key <k)
        {   
            f=-1;
            temp1=temp;
            temp=temp->right;
        }
    }
    if(f==1)
        temp1->left=nullptr;
    if(f==-1)
        temp1->right=nullptr;
    destructCode(temp);
    return true;
}

Elem *inordersuccr(Elem *&p)
{   
    Elem *p1;
    while(p->left!=nullptr)
        Elem *p1=p;
        p=p->left;
    p1->left=nullptr;
    return p;
}














void destructCode(Elem *& p)
{
   // cout<<p->key;
    Elem *temp=new Elem;
    if(p->left!=nullptr && p->right==nullptr)
    {
        p=p->left;
        temp=p->left;
    }
    else if(p->left==nullptr && p->right!=nullptr)
    {
        p=p->right;
        temp=p->right;
    }
    else if(p->left==nullptr && p->right==nullptr)
        free(p);
    else
    {
        //p=p->right;
        temp=inordersuccr(p->right);
     //   cout<<temp->key;
        p->key=temp->key;
        p->data=temp->data;
        
        
    }
    free(temp);
    //balance(_root,_root->key);
    cout<<"\ntree\n";
    printTree(cout,level,_root);
    
}






int main()
{
    char y;
     Elem *node=nullptr;
        //cout<<node<<'\t'<<node->data;
        
    int k,v,i;
    //_root=new Elem();
    _root=nullptr;
    //cout<<_root;
    Elem* lf=NULL;
    cout<<"enter no.of nodes for the tree";
    cin>>i;
    //lf = nullptr;
    cout<<"enter key and data\n";
    while(i!=0)
    {
        cin>> k>> v;
        insert(_root,k,v,lf);
        i--;
    }
    
    //cout<<'\t'<<level<<'\n';
    
     printTree(cout,level,_root);
     cout<<"enter y to continue";
     cin>>y;
     while( y =='y')
     {
     cout<<"to delete enter  'd' and to insert enter 'i' and 'p' to print the avl tree 'n' to exit";
     cin>>y;
     if(y=='d')
     {
         cout<<"delete key to be deleted";
        cin>>k;
        findkey(k);
     }
     if(y=='i')
     {
         cout<<"enter key and data\n";
         cin>> k>> v;
        insert(_root,k,v,lf);
     }
     if(y=='p')
          printTree(cout,level,_root);
     cout<<"to continue enter 'y' exit 'n'";
     cin>>y;
         
    } 
     
    return 0;
}
