#include <stdio.h>
#include <Windows.h>
#include <stdlib.h> //�����Լ��� ��������
#include <time.h>

void main()

{
	int x, y, sel = 0;
	char card[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }; //ī���� ���¸� ��Ÿ���� �迭(0�̸� �޸� 1�̸� �ո� 2�� ��� ������ �ո�)
	char map[4][4], pic[2][8] = { {'@', '#', '%', '&', '*', '<', '^', '>' }, {0, 0, 0, 0, 0, 0, 0, 0 } }; //16���� ĭ�� �� 8���� ���ڿ� �� Ƚ���� �����ϴ� �迭
	POINT firstchoice;
	POINT secondchoice;
	srand((unsigned)time(NULL)); // ��Ȯ�� ������ �����ϱ� ���� ��ɾ�
	
	for (x = 0; x < 4; x++)						//16���� ĭ�� �������� �ֱ����� for
	{
		for (y = 0; y < 4; y++)
		{
			while (1)							//16���� ��� ä���������� ���ѹݺ�
			{
				sel = rand() % 8;				//����8���� �������� �Ѱ��� ����
				if (pic[1][sel] < 2)			//���� Ƚ���� 2���� ������
				{	
					map[x][y] = pic[0][sel];	//���� ���ڸ� 16�� ĭ �ȿ� ��ġ��
					pic[1][sel] += 1;			//���� Ƚ���� 1�� ������Ŵ
					break;						//1���� ��ġ�������Ƿ� �ݺ����� ��������
				}
			}
		}
	}
	
	while (1)									//��ü�� �ݺ���
	{
		
		system("cls");							//ȭ���� ����
		for (y = 0; y < 4; y++)
		{
			for (x = 0; x < 4; x++)
			{
				if (card[y][x] == 0)			//ī���� ���°� �޸��̸� ? �� ��Ÿ��
				{
					printf(" ?  ");	
				}
				else							//ī���� ���°� �ո��̸� �� �ڸ��� ���ڷ� ��Ÿ��
				{
					printf(" %c  ", map[y][x]);
				}
			}
			printf("\n\n");
		}
		while (1)								//ó�� ������ ī���� ��ǥ�� �Է¹���
		{
			printf("ó�� ������ x��ǥ: ");
			scanf("%d", &firstchoice.x);
			printf("ó�� ������ y��ǥ: ");
			scanf("%d", &firstchoice.y);
			if (firstchoice.x < 0 || firstchoice.y < 0 || firstchoice.x >= 4 || firstchoice.y >= 4) //�Է°��� 0~3
			{
				printf("�Է°��� 0����3���� �Դϴ�\n");
			}
			else if (card[firstchoice.y][firstchoice.x] != 0) //�޸��� �ƴ� ī�带 ����������
			{
				printf("�޸��� ī�带 �������ּ���\n");
			}
			else 
			{
				card[firstchoice.y][firstchoice.x] = 2; // ������ ī�带 ��� �ո��� ���·� �ٲ�
				break;
			}
		}
		system("cls");
		for (y = 0; y < 4; y++)
		{
			for (x = 0; x < 4; x++)
			{
				if (card[y][x] == 0)
				{
					printf(" ?  ");
				}
				else
				{
					printf(" %c  ", map[y][x]);
				}

			}
			printf("\n\n");
		}

		while (1)
		{
			printf("�ι�° ������ x��ǥ: ");
			scanf("%d", &secondchoice.x);
			printf("�ι�° ������ y��ǥ: ");
			scanf("%d", &secondchoice.y);
			if (secondchoice.x < 0 || secondchoice.y < 0 || secondchoice.x >= 4 || secondchoice.y >= 4)
			{
				printf("�Է°��� 0����3���� �Դϴ�\n");
			}
			else if (card[secondchoice.y][secondchoice.x] != 0)
			{
				printf("�޸��� ī�带 �������ּ���\n");
			}
			else if (card[secondchoice.y][secondchoice.x] == 0)
			{
				card[secondchoice.y][secondchoice.x] = 2;
				break;
			}
		}
		system("cls");
		for (y = 0; y < 4; y++)
		{
			for (x = 0; x < 4; x++)
			{
				if (card[y][x] == 0)
				{
					printf(" ?  ");
				}
				else
				{
					printf(" %c  ", map[y][x]);
				}

			}
			printf("\n\n");
		}
		Sleep(1000);																	//ȭ���� 1�ʵ��� ����
		if (map[firstchoice.y][firstchoice.x] == map[secondchoice.y][secondchoice.x])  //������ ���� 2���� ������
		{
			card[firstchoice.y][firstchoice.x] = 1;										//ī���� ���¸� �ո����� ����
			card[secondchoice.y][secondchoice.x] = 1;
		}
		else
		{
			card[firstchoice.y][firstchoice.x] = 0;										//������ ����2���� ���� ������ �ٽ� ������
			card[secondchoice.y][secondchoice.x] = 0;
		}
		if (card[0][0] == 1 && card[0][1] == 1 && card[0][2] == 1 && card[0][3] == 1 && card[1][0] == 1 && card[1][1] == 1 && card[1][2] == 1 && card[1][3] == 1 && card[2][0] == 1 && card[2][1] == 1 && card[2][2] == 1 && card[2][3] == 1 && card[3][0] == 1 && card[3][1] == 1 && card[3][2] == 1 && card[3][3] == 1)
		{
			printf("������\n");
			break;						//��� �ո��� �Ǹ� ����
		}
	}
}