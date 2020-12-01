#include <stdio.h>
#include <stdlib.h>

//리스트를 구성할 노드
typedef struct _node
{
	int age;
	struct _node* next;
}Node;

//인자로 데이터(나이)를 넘겨받음
//노드를 새로 생성하여 데이터를 저장하고 노드의 주소를 리턴함
Node* create_node(int age)
{
	Node* new_node = (Node *)calloc(1, sizeof(Node));
	new_node->age = age;
	new_node->next = NULL;
	
	return new_node;
}

//리스트에 새로운 노드를 오름차순으로 연결시켜줌
Node *add_node_upper(Node* head, Node* new_node)
{
	//리스트가 텅 비어있는경우
	if (head == NULL)
	{
		head = new_node;
		return head;
	}
	
	//리스트가 존재할경우
	else
	{
		Node* move = head;
		Node* prev = NULL;
		while (move != NULL)
		{
			//현재 데이터(나이)보다 더 큰 값을 만났을경우
			if (move->age >= new_node->age)
			{
				//맨앞에 경우
				if (move == head)
				{
					new_node->next = move;
					head = new_node;
				}
				//중간에서 발견한 경우
				else
				{
					new_node->next = move;
					prev->next = new_node;
				}
				return head;
			}
			//이전 노드를 가리키는 prev와 move 갱신
			else
			{
				prev = move;
				move = move->next;
			}
		}
		//맨마지막에 new_node를 연결하는 경우
		prev->next = new_node;
		return head;
	}
}

//리스트에 존재하는 데이터(나이)를 출력
void show_list(Node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->age);
		head = head->next;
	}
	return;
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;

	while (1)
	{
		int select = 0;
	
		printf("나이를 입력하세요. 양수를 입력하지 않으면 종료됩니다.\n");
		scanf("%d", &select);

		//양수가 아닐경우 종료
		if (select < 1)
			break;
		else
		{
			Node* new_node = create_node(select);
			head = add_node_upper(head, new_node);
			show_list(head);
			printf("\n");
		}
	}

	return 0;
}