//
//  Header.h
//  LinkedList
//

#ifndef linkedlist_h
#define linkedlist_h

//#include <opencl-c.h>

namespace ECE17 {

  //---------------------------------------------------------------

  template <typename T>
  class LinkedList {
  public:
    
    struct Node; //pre-define so compiler doesn't complain...
    class INodeVisitor;
    //STUDENT: Define OCF methods for LinkedList here...
    LinkedList(){
      count=0;
      root= nullptr;
    }
    LinkedList(const LinkedList &aLinkedList){
      if (aLinkedList.root== nullptr){
          count=0;
          root=nullptr;
          return;
      }
      else{
          count=aLinkedList.length;
          root=new Node(aLinkedList.root->value, nullptr);
          Node* cur=root;
          Node* copy=aLinkedList.root;
          for (size_t i=0;i<(count-1);i++){
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
      count=aLinkedList.length;
      return *this;
    }
    ~LinkedList(){
      Node* cur=root;
      Node* nxt;
      for(size_t i=0;i<count;i++){
          nxt=cur->next;
          delete cur;
          cur=nxt;
      }
    }


      //STUDENT: Add Node struct here...
    struct Node {
      //Add OCF methods here...
      Node(T aValue,Node *aNodePtr= nullptr){
          value=aValue;
          next=aNodePtr;
      }
      Node(){
          value = 0;
          next= nullptr;
      }
      Node(const Node &aNode){
          *this=aNode;
      }
      Node& operator=(const Node &aNode){
          value=aNode.value;
          next=aNode.next;
          return *this;
      }
      Node& operator()(INodeVisitor & aINodeVisitor){
          aINodeVisitor.visit(*this);
          return *this;
      }
      ~Node(){}
      Node *next;
      T value;
//      static size_t nodeCount;
//      void *operator new(size_t size){
//          nodeCount++;
//          return ::new Node;
//      }
//      void operator delete (void *aNode){
//          nodeCount--;
//          free(aNode);
//      }
    };
    //---------------------------------------------------------------

      Node* first() const{
          return root;
      }//retrieve first node in the list.
      Node* last() const{
          Node* cur=root;
          size_t i=1;
          while (i<count){
              cur=cur->next;
              i++;
          }
          return cur;
      }
      size_t size() {
          return count;
      }   //return # of items in the list...
      Node* find(const T &aValue, Node *anOrigin=nullptr){
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
      Node* append(const T &aValue){
          Node *newNode=new Node(aValue,nullptr);
          if(count==0){
              root=newNode;
              count+=1;
              return root;
          }
          else{
              Node* cur=root;
              while (cur->next!= nullptr){
                  cur=cur->next;
              }
              cur->next=newNode;
              cur=cur->next;
              count+=1;
              return cur;
          }
      }
      Node* insertAfter(const T &aValue, Node *anOrigin=nullptr){
          Node *newNode=new Node(aValue, nullptr);
          if(anOrigin== nullptr){
              newNode->next=root;
              root=newNode;
              count+=1;
              return root;
          }
          else{
              Node* OriginNext=anOrigin->next;
              Node* cur=newNode;
              anOrigin->next= cur;
              cur->next=OriginNext;
              count+=1;
              return cur;

          }
      }
      Node* remove(const T &aValue) {
          if (count == 0) {
              return nullptr;
          }
          if (root->value == aValue) {
              if (count == 1) {
                  Node *res = root;
                  root = nullptr;
                  count -= 1;
                  return res;
              }
              Node *res = root;
              root = root->next;
              count -= 1;
              return res;
          } else {
              Node *cur = root;
              Node *nxt = cur->next;
              while (nxt != nullptr) {
                  if (nxt->value == aValue) {
                      cur->next = nxt->next;
                      count -= 1;
                      return nxt;
                  }
                  cur = nxt;
                  nxt = nxt->next;
              }
              return nullptr;
          }
      }
      class INodeVisitor{
      public:
          virtual void visit(const Node& aNode)=0;
      };

      LinkedList& visitWith(INodeVisitor &aVisitor) {
          //walk through your list of nodes and call Node::operator() //function call op...
          Node* NodePtr=root;
          for(size_t i=0;i<count;i++){
              Node curNode=(*NodePtr);
              curNode(aVisitor);
              NodePtr = NodePtr->next;
          }
        return *this;
      }
  protected:
    Node    *root;  //FRONT of list (may be nullptr)
    size_t  count;
  };

}

#endif /* linkedlist_h */

