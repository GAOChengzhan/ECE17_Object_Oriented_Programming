//
//  LinkedList.hpp
//

#ifndef linkedlist_h
#define linkedlist_h

namespace ECE17 {


  //STUDENT: Add Node struct here...
  struct Node {
      //Add OCF methods here...
      Node(int aValue,Node *aNodePtr= nullptr){
          value=aValue;
          next=aNodePtr;
      }
      Node(){
          value=0;
          next= nullptr;
      }
      Node(const Node &aNode){
          *this=aNode;
      }
      Node operator=(const Node &aNode){
          value=aNode.value;
          next=aNode.next;
          return *this;
      }
      ~Node(){}
      Node *next;
      int  value;
      static size_t nodeCount;
      void *operator new(size_t size){
          nodeCount++;
          return ::new Node;
      }
      void operator delete (void *aNode){
          nodeCount--;
          free(aNode);
      }
  };
  //---------------------------------------------------------------
        
  class LinkedList {
  public:

    //--------------------------------------------------------------
      
    //STUDENT: Define OCF methods for LinkedList here...
    LinkedList(){
        length=0;
        root= nullptr;
    }
    LinkedList(const LinkedList &aLinkedList){
        if (aLinkedList.root== nullptr){
            length=0;
            root=nullptr;
            return;
        }
        else{
            length=aLinkedList.length;
            root=new Node(aLinkedList.root->value, nullptr);
            Node* cur=root;
            Node* copy=aLinkedList.root;
            for (size_t i=0;i<(length-1);i++){
                copy=copy->next;
                Node *newNode=new Node(copy->value,copy->next);
                cur->next=newNode;
                cur=cur->next;
            }

        }
    }
    LinkedList& operator=(const LinkedList& aLinkedList){
        if(aLinkedList.root== nullptr){
            return *this;
        }
        root->value=aLinkedList.root->value;
        root->next=aLinkedList.root->next;
        length=aLinkedList.length;
        return *this;
    }
    ~LinkedList(){
        Node* cur=root;
        Node* nxt;
        for(size_t i=0;i<length;i++){
            nxt=cur->next;
            delete cur;
            cur=nxt;
        }
    }

    //STUDENT: Add other methods described in assignment here...
    Node* first() const{
        return root;
    }//retrieve first node in the list.
    size_t size() {
        return length;
    }   //return # of items in the list...
    Node* find(const int &aValue, Node *anOrigin=nullptr){
        if (anOrigin==nullptr){
            Node* cur=root;
            while(cur!= nullptr){
                if (cur->value==aValue){
                    return cur;
                }
                else{
                    cur=cur->next;
                }
            }
            return nullptr;
        }
        else {
            Node *cur = anOrigin;
            while (cur != nullptr) {
                if (cur->value == aValue) {
                    return cur;
                } else {
                    cur = cur->next;
                }
            }
            return nullptr;
        }
    }
    Node* append(const int &aValue){
        Node *newNode=new Node(aValue,nullptr);
        if(length==0){
            root=newNode;
            length+=1;
            return root;
        }
        else{
            Node* cur=root;
            while (cur->next!= nullptr){
                cur=cur->next;
            }
            cur->next=newNode;
            cur=cur->next;
            length+=1;
            return cur;
        }
    }
    Node* insertAfter(const int &aValue, Node *anOrigin=nullptr){
        Node *newNode=new Node(aValue, nullptr);
        if(anOrigin== nullptr){
            newNode->next=root;
            root=newNode;
            length+=1;
            return root;
        }
        else{
            Node* OriginNext=anOrigin->next;
            Node* cur=newNode;
            anOrigin->next= cur;
            cur->next=OriginNext;
            length+=1;
            return cur;

        }
    }
    Node* remove(const int &aValue){
        if(length==0){
            return nullptr;
        }
        if(root->value==aValue){
            if (length==1){
                Node*res=root;
                root= nullptr;
                length-=1;
                return res;
            }
            Node* res=root;
            root=root->next;
            length-=1;
            return res;
        }
        else {
            Node *cur = root;
            Node *nxt = cur->next;
            while (nxt!= nullptr) {
                if (nxt->value == aValue) {
                    cur->next=nxt->next;
                    length-=1;
                    return nxt;
                }
                cur = nxt;
                nxt = nxt->next;
            }
            return nullptr;
        }
    }
      
  protected:
    //STUDENT: Add linked-list data properties here...
    size_t length;
    Node *root;
  };
    size_t Node::nodeCount=0;

}

#endif /* linkedlist_h */

