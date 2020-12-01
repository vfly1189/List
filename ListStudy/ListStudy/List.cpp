#include <stdio.h>
#include <stdlib.h>

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
	
		printf("���̸� �Է��ϼ���. ����� �Է����� ������ ����˴ϴ�.\n");
		scanf("%d", &select);

		//����� �ƴҰ�� ����
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