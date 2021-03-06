#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stackNode{
    element data;
    struct StackNode *link;
} stackNode;

typedef struct{
    stackNode *top;
} linkedStackType;

//초기화
void init(linkedStackType *s){
    s->top = NULL; //s->top에 NULL을 가리킴
}

//공백 상태 검출 함수
int is_empty(linkedStackType *s){
    return (s->top == NULL); // s->top == NULL로 반환
}

//포화 상태 검출 함수
int is_full(linkedStackType *s){
    return 0; //0반환
}

//출력 함수
void print_stack(linkedStackType *s){
    //stackNode타입의 포인터변수 p는 s->top의 값부터
    //p가 공백상태가 아닐 때까지 반복
    //p->link로 이동하면서 
    for (stackNode *p = s->top; p!=NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//삽입함수
void push(linkedStackType *s, element item){
    //stackNode사이즈의 크기의 stackNode구조체를 동적할당한 후 포인터변수 temp에 복사
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item; //temp변수의 data에 매개변수의 item값을 복사
    temp->link = s->top; //temp의 link(temp 다음 데이터)는 top을 가리킴
    s->top = temp; //top이  temp를 가리킴
}

//삭제함수
element pop(linkedStackType *s){
    if(is_empty(s)){
        fprintf("stderr","스택이 비어있습니다.\n");
        exit(1);
    } else{
        stackNode *temp = s->top; //포인터변수 temp의 값에 현재위치 복사
        int data = temp->data; //temp의 data값은 data에 복사
        s->top = s->top->link; //top이 link(=temp노드의 link)를 s->top이 가리키게 됨
        free(temp); //temp노드 메모리해제
        return data; //변수 data 반환
    }
}

int main(void){
    linkedStackType s; // linkedStackType의 변수 s 선언
    init(&s); //초기화함수 실행함 주소로 접근할 수 있도록 인자에 주소연산자 사용함
    push(&s, 1); print_stack(&s); // 1 삽입, 출력
    push(&s, 2); print_stack(&s); // 2 삽입, 출력
    push(&s, 3); print_stack(&s); // 3 삽입, 출력
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    
}
