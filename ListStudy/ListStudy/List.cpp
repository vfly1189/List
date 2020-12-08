#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int list_length = 0;

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
	for (int i = 1; head != NULL; head = head->next)
	{
		printf("%d : %d\n", i++, head->age);
	}
	return;
}

//리스트에 원하는 레코드가 있는지 검색
bool search_data(Node *head, int age)
{
	//0은 아직 못 찾음, 1은 찾음
	int flag = 0;
	for (; head != NULL; head = head->next)
	{
		if (head->age == age)
		{
			flag = 1; break;
		}
	}
	if (flag == 1) return true;
	else return false;
}

//리스트에서 레코드 삭제
Node* delete_data(Node* head, int record_num)
{
	Node* prev = NULL;
	Node* move = head;
	for (int i = 0; i < record_num - 1; i++)
	{
		prev = move;
		move = move->next;
	}
	//맨 처음 레코드를 삭제할때
	if (move == head)
	{
		head = move->next;
		move->next = NULL;
		free(move);
	}
	//중간단계 레코드를 삭제할때
	else if (move->next == NULL)
	{
		prev->next = NULL;
		free(move);
	}
	//맨끝 레코드를 삭제할때
	else
	{
		prev->next = move->next;
		move->next = NULL;
		free(move);
	}
	return head;
}


int main()
{
	Node* head = NULL;
	Node* tail = NULL;

	while (1)
	{
		int select = 0;
		system("cls");
		printf("List Test Program\n");
		printf("1. add   2. search   3. delete   4. show\n");
		scanf("%d", &select);

		//리스트에 추가
		if (select == 1)
		{
			int age;
			printf("나이를 입력하세요 : "); 
			scanf("%d", &age);
			Node* new_node = create_node(age);
			head = add_node_upper(head, new_node);
			printf("\ncomplete\n\n");
			list_length++;
		
			getchar();
			getchar();
		}
		//리스트에서 검색
		else if (select == 2)
		{
			int want_search;
			printf("찾고자 하는 나이를 입력하세요 : ");
			scanf("%d", &want_search);

			//리스트에 존재하면 true 없으면 false를 리턴함
			if (search_data(head, want_search)) printf("리스트에 존재합니다\n\n");
			else printf("리스트에 존재하지 않습니다\n\n");
			
			//1초 딜레이
			Sleep(1000);
		}
		//리스트에서 삭제
		else if (select == 3)
		{
			show_list(head);

			int record_num;
			printf("삭제하고자 하는 레코드의 번호를 입력하세요 : ");
			scanf("%d", &record_num);

			if (record_num > list_length)
			{
				printf("\n다시 입력하세요.\n");
				Sleep(1000);
			}

			head = delete_data(head, record_num);
		}
		//리스트 전체 출력
		else if (select == 4)
		{
			show_list(head);
			printf("\n엔터를 입력하세요\n");
			//버퍼에 남아있는 엔터받아드림
			getchar();
			//아무키 입력이나 들어올때 까지 대기
			getchar();
		}
	}

	return 0;
}