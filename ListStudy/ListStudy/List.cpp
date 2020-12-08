#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int list_length = 0;

//����Ʈ�� ������ ���
typedef struct _node
{
	int age;
	struct _node* next;
}Node;

//���ڷ� ������(����)�� �Ѱܹ���
//��带 ���� �����Ͽ� �����͸� �����ϰ� ����� �ּҸ� ������
Node* create_node(int age)
{
	Node* new_node = (Node *)calloc(1, sizeof(Node));
	new_node->age = age;
	new_node->next = NULL;
	
	return new_node;
}

//����Ʈ�� ���ο� ��带 ������������ ���������
Node *add_node_upper(Node* head, Node* new_node)
{
	//����Ʈ�� �� ����ִ°��
	if (head == NULL)
	{
		head = new_node;
		return head;
	}
	
	//����Ʈ�� �����Ұ��
	else
	{
		Node* move = head;
		Node* prev = NULL;
		while (move != NULL)
		{
			//���� ������(����)���� �� ū ���� ���������
			if (move->age >= new_node->age)
			{
				//�Ǿտ� ���
				if (move == head)
				{
					new_node->next = move;
					head = new_node;
				}
				//�߰����� �߰��� ���
				else
				{
					new_node->next = move;
					prev->next = new_node;
				}
				return head;
			}
			//���� ��带 ����Ű�� prev�� move ����
			else
			{
				prev = move;
				move = move->next;
			}
		}
		//�Ǹ������� new_node�� �����ϴ� ���
		prev->next = new_node;
		return head;
	}
}

//����Ʈ�� �����ϴ� ������(����)�� ���
void show_list(Node* head)
{
	for (int i = 1; head != NULL; head = head->next)
	{
		printf("%d : %d\n", i++, head->age);
	}
	return;
}

//����Ʈ�� ���ϴ� ���ڵ尡 �ִ��� �˻�
bool search_data(Node *head, int age)
{
	//0�� ���� �� ã��, 1�� ã��
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

//����Ʈ���� ���ڵ� ����
Node* delete_data(Node* head, int record_num)
{
	Node* prev = NULL;
	Node* move = head;
	for (int i = 0; i < record_num - 1; i++)
	{
		prev = move;
		move = move->next;
	}
	//�� ó�� ���ڵ带 �����Ҷ�
	if (move == head)
	{
		head = move->next;
		move->next = NULL;
		free(move);
	}
	//�߰��ܰ� ���ڵ带 �����Ҷ�
	else if (move->next == NULL)
	{
		prev->next = NULL;
		free(move);
	}
	//�ǳ� ���ڵ带 �����Ҷ�
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

		//����Ʈ�� �߰�
		if (select == 1)
		{
			int age;
			printf("���̸� �Է��ϼ��� : "); 
			scanf("%d", &age);
			Node* new_node = create_node(age);
			head = add_node_upper(head, new_node);
			printf("\ncomplete\n\n");
			list_length++;
		
			getchar();
			getchar();
		}
		//����Ʈ���� �˻�
		else if (select == 2)
		{
			int want_search;
			printf("ã���� �ϴ� ���̸� �Է��ϼ��� : ");
			scanf("%d", &want_search);

			//����Ʈ�� �����ϸ� true ������ false�� ������
			if (search_data(head, want_search)) printf("����Ʈ�� �����մϴ�\n\n");
			else printf("����Ʈ�� �������� �ʽ��ϴ�\n\n");
			
			//1�� ������
			Sleep(1000);
		}
		//����Ʈ���� ����
		else if (select == 3)
		{
			show_list(head);

			int record_num;
			printf("�����ϰ��� �ϴ� ���ڵ��� ��ȣ�� �Է��ϼ��� : ");
			scanf("%d", &record_num);

			if (record_num > list_length)
			{
				printf("\n�ٽ� �Է��ϼ���.\n");
				Sleep(1000);
			}

			head = delete_data(head, record_num);
		}
		//����Ʈ ��ü ���
		else if (select == 4)
		{
			show_list(head);
			printf("\n���͸� �Է��ϼ���\n");
			//���ۿ� �����ִ� ���͹޾Ƶ帲
			getchar();
			//�ƹ�Ű �Է��̳� ���ö� ���� ���
			getchar();
		}
	}

	return 0;
}