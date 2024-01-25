#include "iostream"
using namespace std;

class Node{
public: 
	int val;
	Node *next;
};

class linklist{
	public:
	    Node  *head;
	    Node *last;
	    int length=0;
	    linklist(int arr[], int l);
	    int getLength();
	    int getdata();
	    int getDataAt(int position); 
	    void appendAtEnd(int data);
        void insertdata(int data, int pos);
	    ~linklist();
	
};

int linklist::getLength(){
	return length;
}


linklist::linklist(int arr[] , int l){
      head = new Node;
	  head->val=0;
 	  head->next=NULL;
	  Node *temp=head;
          
	 for (int i=0;i<l;i++){
	    
	    temp->next=new Node;
	    temp=temp->next;	
	    temp->val=arr[i];
	    temp->next=NULL;
       	length=i+1;
	  }

}


 int linklist::getdata(){
	Node *k=head->next;

        while(k != nullptr){
		cout<<k->val<<endl;
		k=k->next;
	}

	
}


void linklist::appendAtEnd(int data){
	Node *q = head;
	Node *n = new Node;
	n->val=data;
	n->next=NULL;
	if (length%2 ==0){
    	q=q->next;
	   for (int k=0;k<=length/2;k=k+1.5){
	    	if (q->next->next==NULL){
			q->next->next=n;
			break;
		 }
		 q=q->next->next;
	    }
    }
   else{
   	    q=q->next->next;
   	    for (int k=0;k<length/2;k=k+1.5){
		    if (q->next->next==NULL){
			 q->next->next=n;
			 break;
		   }
		   q=q->next->next;
	   }
   }
	length=length+1;
}

int linklist::getDataAt(int position ){
	Node *temp = head;
	if (position%2 == 0){
		temp=temp->next;
		for(int j=0;j<=length;j=j+2){
			if (j==position){
				return temp->val;
			}
			temp=temp->next->next;
		}
	}
	else{
		temp=temp->next->next;
		for(int j=0;j<=length/2;j=j+2){
			if (j==position){
				return temp->val;
			}
			temp=temp->next->next;
		}
	}
}


void linklist::insertdata(int data, int pos){
    Node *newnode= new Node;
	Node *temp=head;
	newnode->val=data;
	newnode->next=NULL;
	
	
	if (pos==0){
		newnode->next=temp->next;
		temp->next=newnode;
	}
	else{
	
	int prenode_Loc=pos-1;
	if (prenode_Loc%2 == 0){
	
	temp=temp->next;
		for (int i=0; i<=length/2;i=i+2){
		
				if (i == prenode_Loc){
					newnode->next=temp->next;
					temp->next=newnode;
					
				}
    	
    		temp=temp->next->next;
  		}
    }


	else{
	temp=temp->next->next;
			for (int i=1; i<=length/2;i=i+2){
				
				if (i == prenode_Loc){
					newnode->next=temp->next;
					temp->next=newnode;
				}
    	
    			temp=temp->next->next;
   			}
	
	}
	
}
length=length+1;

}

linklist::~linklist(){
	Node *x;
	x=head;
	for (int l=0; l<length;l++){
	if (x->next==NULL){
		delete x ;
		break;
	}
	else{
	    x=x->next;
	    delete head;
	    head = x ; }
	}

	cout<<"destructor: deallocated memory successfully ...."<<endl;
}
main(){
	int arr[6] = {1,2,3,4,5,6};
	linklist obj(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<"available data in the linked-list : "<<endl;
	obj.getdata();
	obj.insertdata(23, 0);
	
	cout<<"getting the data after insert :"<<endl;
	cout<< obj.getDataAt(0) <<endl;
	cout<< obj.getDataAt(4) <<endl;
	
	obj.appendAtEnd(25);
	cout<<"available data in the linked-list after append: " << endl ;
	obj.getdata();
}
	               
