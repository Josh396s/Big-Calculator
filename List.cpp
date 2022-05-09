//**********************************************************************************
// Joshua Angel, joangel
// PA6
// List.cpp
// Implementation for List ADT
//**********************************************************************************

#include<string>
#include<stdexcept>
#include"List.h"

// Private Constructor --------------------------------------------------------

// Node constructor
List::Node::Node(ListElement x){
   next = nullptr;
   prev = nullptr;
   data = x;
}

// Class Constructors & Destructors -------------------------------------------

// Creates a new List in the empty state
List::List(){
	frontDummy = new Node(-1);
	backDummy = new Node(-1);
   	frontDummy->next = backDummy;
   	backDummy->prev = frontDummy;
	beforeCursor = frontDummy;
	afterCursor = backDummy;
	pos_cursor = 0;
	num_elements = 0;
}

// Copy constructor.
List::List(const List& L){
	//Empty List
    frontDummy = new Node(-1);
	backDummy = new Node(-1);
   	frontDummy->next = backDummy;
   	backDummy->prev = frontDummy;
    pos_cursor = 0;
    num_elements = 0;

   	//Load elements of L into List
   	Node* N = L.frontDummy->next;
   	while(N->next != nullptr){
   		this->insertBefore(N->data);
   		N = N->next;
   	}
}

// Destructor
List::~List(){
    clear();
    delete(backDummy);
    delete(frontDummy);
    return;
}

// Access functions --------------------------------------------------------

// length()
// Returns the length of this List.
int List::length() const{
	return num_elements;
}

// front()
// Returns the front element in this List.
// pre: length()>0
ListElement List::front() const{
	if(num_elements <= 0){
		throw std::length_error("List: front(): empty List");
	}
	return(frontDummy->next->data);
}

// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const{
	if(num_elements <= 0){
		throw std::length_error("List: back(): empty List");
	}
	return(backDummy->prev->data);
}

// position()
// Returns the position of cursor in this List: 0 <= position() <= length().
int List::position() const{
	return (pos_cursor);
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<length()
ListElement List::peekNext() const{
    if(position() >= length()){
        throw std::out_of_range("List: peekNext(): Cursor is at back of List");
    }
    return(afterCursor->data);
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const{
    if(position() <= 0) {
        throw std::out_of_range("List: peekPrev(): Cursor is at front of List");
    }
    return(beforeCursor->data);
}

// Manipulation procedures -------------------------------------------------

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear(){
    moveFront();
    while(length() > 0){
        eraseAfter();
    }
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
    afterCursor = frontDummy->next;
    beforeCursor = frontDummy;
    pos_cursor = 0;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack(){
    beforeCursor = backDummy->prev;
    afterCursor = backDummy;
    pos_cursor = length();
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that was passed over.
// pre: position()<length() 
ListElement List::moveNext(){
    if(position() >= length()){
        throw std::out_of_range("List: moveNext(): Cursor is at back of list");
    }
    beforeCursor = afterCursor;
    afterCursor = afterCursor->next;
    pos_cursor++;
    return beforeCursor->data;
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that was passed over.
// pre: position()>0
ListElement List::movePrev(){
    if(position() <= 0){
        throw std::out_of_range("List: movePrev(): Cursor is at front of list");
    }
    afterCursor = beforeCursor;
    beforeCursor = beforeCursor->prev;
    pos_cursor--;
    return afterCursor->data;
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x){
	Node* N = new Node(x);
    N->data = x;
	if(num_elements == 0) {//If List is Empty
        N->next = backDummy;
        N->prev = frontDummy;
        N->next->prev = N;
        N->prev->next = N;
        backDummy->prev = N;
        frontDummy->next = N;
        afterCursor = N;
        beforeCursor = frontDummy;
        pos_cursor = 0;
        num_elements++;
        return;
    }
    else if(position() == 0){//If cursor is at front
        N->next = frontDummy->next;
        frontDummy->next = N;
        N->prev = frontDummy;
        afterCursor = N;
        beforeCursor = frontDummy;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
            N->prev->next = N;
        }
        num_elements++;
        return;
    }
    else if(position () == length()){//If cursor is at back
        N->next = backDummy;
        N->prev = beforeCursor;
        afterCursor = N;
        beforeCursor = N->prev;
        backDummy->prev = N;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
            N->prev->next = N;
        }
        num_elements++;
        return;
    }
    else {//Anywhere else in the List
        N->next = afterCursor;
        N->prev = beforeCursor;
        afterCursor = N;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
            N->prev->next = N;
        }
        num_elements++;
    }
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x){
    Node* N = new Node(x);
    N->data = x;
    if(num_elements == 0) {//If List is Empty
        N->next = backDummy;
        N->prev = frontDummy;
        N->next->prev = N;
        N->prev->next = N;
        backDummy->prev = N;
        frontDummy->next = N;
        afterCursor = backDummy;
        beforeCursor = N;
        pos_cursor = 1;
        num_elements++;
        return;
    }
    else if(position() == 0){//If cursor is at front
        N->next = frontDummy->next;
        frontDummy->next = N;
        N->prev = frontDummy;
        afterCursor = N->next;
        beforeCursor = N;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
            N->prev->next = N;
        }
        pos_cursor++;
        num_elements++;
        return;
    }
    else if(position() == length()){//If cursor is at back
        N->next = backDummy;
        N->prev = beforeCursor;
        afterCursor = backDummy;
        beforeCursor = N;
        backDummy->prev = N;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
            N->prev->next = N;
        }
        pos_cursor++;
        num_elements++;
        return;
    }
    else {//Anywhere else in the List
        N->next = afterCursor;
        N->prev = beforeCursor;
        beforeCursor = N;
        if(N->next != nullptr){
            N->next->prev = N;
        }
        if(N->prev != nullptr){
           N->prev->next = N;
        }
        pos_cursor++;
        num_elements++;
    }
}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x){
    if(position() >= length()){
        throw std::length_error("List: setAfter(): Cursor is at back of list");
    }
    afterCursor->data = x;
    return;
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x){
    if(position() <= 0){
        throw std::length_error("List: setBefore(): Cursor is at front of list");
    }
    beforeCursor->data = x;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<length()
void List::eraseAfter(){
    if(position() >= length()) {
        throw std::length_error("List: eraseAfter(): Cursor is at back of list");
    }
    Node* head = frontDummy->next;
    Node* del = afterCursor;
    if(head == del){//If the node is the head
        afterCursor = del->next;
    }
    if(del->next != nullptr){
        del->next->prev = del->prev;
    }
    if(del->prev != nullptr){
        del->prev->next = del->next;
    }
    afterCursor = del->next;
    num_elements--;
    delete(del);
    return;
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore(){
    if(position() <= 0){
        throw std::length_error("List: eraseBefore(): Cursor is at front of list");
    }
    Node* tail = backDummy->prev;
    Node *del = beforeCursor;

    if(tail == del){//If the node is at the tail
        beforeCursor = beforeCursor->prev;
    }
    if(del->next != nullptr){
        del->next->prev = del->prev;
    }
    if(del->prev != nullptr){
        del->prev->next = del->next;
    }
    beforeCursor = del->prev;
    pos_cursor--;
    num_elements--;
    delete(del);
    return;
}

// Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in the direction front-to-back)
// for the first occurrence of element x. If x is found, places the cursor immediately after the found
// element, then returns the final cursor position.
// If x is not found, places the cursor at position length(), and returns -1.
int List::findNext(ListElement x){
    Node *N;
    for(N = afterCursor; N->next != nullptr; N = N->next){
        if(N->data == x){
            pos_cursor++;
            beforeCursor = N;
            afterCursor = N->next;
            return pos_cursor;
        }
        pos_cursor++;
    }
    pos_cursor = length();
    return -1;
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in the direction back-to-front)
// for the first occurrence of element x. If x is found, places the cursor immediately before the found
// element, then returns the final cursor position.
// If x is not found, places the cursor at position 0, and returns -1.
int List::findPrev(ListElement x){
    Node *N;
    for(N = beforeCursor; N->prev != nullptr; N = N->prev){
        if(N->data == x){
            pos_cursor--;
            afterCursor = N;
            beforeCursor = N->prev;
            return pos_cursor;
        }
        pos_cursor--;
    }
    pos_cursor = 0;
    return -1;
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost occurrence of each element,
// and removing all other occurrences. The cursor is not moved with respect to the retained elements,
// i.e. it lies between the same two retained elements that it did before cleanup() was called.
void List::cleanup(){
    int First = position();

    moveFront();
    moveNext();
    Node *N;
    Node *j;
    for(N = frontDummy->next; N->next!= nullptr; N=N->next){
        j = N->next;
        if(j->data == N->data){
            moveNext();
            eraseBefore();
            j = N->next;
            if(j->data == N->data){
                moveNext();
                eraseBefore();
                j = N->next;
                if(position() < First){
                    First--;
                }
            }
            if(position() < First){
                First--;
            }
        }
        while(findNext(N->data) != -1){
            eraseBefore();
            if(position() < First){
                First--;
            }
        }
        moveFront();
        findNext(j->data);
    }

    moveFront();
    for(int i = 1; i <= First; i++){
       moveNext();
    }
}


// concat()
// Returns a new List consisting of the elements of this List, followed by
// the elements of L. The cursor in the returned List will be at position 0.
List List::concat(const List& L) const{
    List J;
    Node* N = this->frontDummy->next;
    Node* M = L.frontDummy->next;
    while(N->next != nullptr) {
        J.insertBefore(N->data);
        N = N->next;
    }
    while(M->next != nullptr){
        J.insertBefore(M->data);
        M = M->next;
    }
    J.pos_cursor = 0;
    return J;
}

// to_string()
// Returns a string representation of this List consisting of a comma separated sequence of elements,
// surrounded by parentheses.
std::string List::to_string() const{
    Node *N;
    std::string s = "";
    for(N = frontDummy->next; N->next!= nullptr; N=N->next){
        if(N->next->next == nullptr){
            s += std::to_string(N->data);
            break;
        } else {
            s += std::to_string(N->data) + ", ";
        }
    }
    return s;
}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) const{
    bool eq = false;
    if(this->num_elements != R.num_elements){
        return eq;
    }
    Node* N = nullptr;
    Node* M = nullptr;
    N = this->frontDummy->next;
    M = R.frontDummy->next;
    while(N != nullptr){
        if(N->data != M->data){
            return eq;
        }
        N = N->next;
        M = M->next;
    }
    eq = true;
    return eq;
}

// Overridden Operators -----------------------------------------------------
   
// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ){
    return stream << L.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged.
bool operator==( const List& A, const List& B ){
    return A.List::equals(B);
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ){
    if(this != &L){//Not self assignment
        List temp = L;

        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(beforeCursor, temp.beforeCursor);
        std::swap(afterCursor, temp.afterCursor);
        std::swap(num_elements, temp.num_elements);
        std::swap(pos_cursor, temp.pos_cursor);
    }
    return *this;
}