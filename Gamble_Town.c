	#include <stdio.h>	// gotoxy(0, 28);
	#include <stdlib.h>
	#include <windows.h>
	#include <time.h>
	#include <conio.h>
	#include <math.h>
	
	float Money = 500.12;									// ȭ�� (��)
	int HP = 100;										// ü�� ������
	int Gold_Have = 0;									// �ݱ� ����
	int Saving[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	// ����
	int House_Have = 0;									// �� ����
	
	
	int Day = 1;										// ��¥ ī����

	// ������
	int Drink = 0;			// �ִ� ü�� ����
	int Whistle = 0;		// ȣ����
	

// ȭ�� �׸���
	void Edge();
	void Title();
	void Status();
	void Map_1();
	void Big_Clear();
	void Long_Clear();
	void Small_Clear();
	void Loading_Clear();
	void Full_Clear();
	
	void Set_Color(int Text);
	
	
// �ʱ� �޴�
	void First_Menu();
	void First_inf();
		
// ����
	int YN();
	void ing(float n);
	void gotoxy(int x, int y);
	int Ten_Square(int num);
	int Ten_Divide(int num);
	
	
// ����
	// ��Ŀ
	void Poker_Room();
	void Poker_Room_inf();
	void Show(int x, int y, int N, int T, int i);
	void Poker_Five_Draw_1();
	void Poker_Five_Draw_1_inf();
	void ShowCard(int N[], int T[], int C[]);
	
	// �ζ�
	void Lottery();						
	void Lottery_inf();
	
	// �� �ŷ���
	int Gold_Store(float Price, int *Have);
	void Gold_inf();
	int Gold_Change(float *Price, int *Big);
	
	// �渶��
	void Race();
	void Race_inf();
	int Race_Start(int Select);
	
// �ü�
	// ȣ��
	void Hotel();
	
	// ���۰���
	void Hole();
	void Hole_inf();
	int Hole_Purchase(int *M, int Can);
	
	//����
	void Bank();
	void Bank_inf();
	
	// �ε���
	void Real_Estate();
	void Real_Estate_inf();
	
// ��Ÿ
	// ������ Ȯ��
	void Item_Check();
	
	// ��
	void House();
	
	
//////////////////////////////////////////////////////////////////////////////// �ڵ� ����

// �׸���
	void Edge()
	{
		int i;
		
		for(i = 0; i <= 42; i++)			// ���� ����
		{
			gotoxy(i * 2, 0);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(i * 2, 20);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(i * 2, 26);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(i * 2, 28);
			printf("%c%c", 0xa2, 0xcc);
		}
			
		for(i = 0; i<= 28; i++)				// ���� ����
		{
			gotoxy(0, i);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(84, i);
			printf("%c%c", 0xa2, 0xcc);
		}
		
		for(i = 0; i < 10; i++)			// ���� ����
		{
			gotoxy(88 + i * 2, 20);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(88 + i * 2, 26);
			printf("%c%c", 0xa2, 0xcc);
		}
		
		for(i = 0; i < 6; i++)				// ���� ����
		{
			gotoxy(88, 20 + i);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(106, 20 + i);
			printf("%c%c", 0xa2, 0xcc);
		}
	}

	void Title()
	{
		int i, j;
		
		i = 0xa1;
		j = 0xe1;

// Gamble		
// 1	
		Set_Color(12);
		gotoxy(2, 2);
		printf("      %c%c%c%c%c%c       %c%c      ", i, j, i, j, i, j, i, j);
		printf("%c%c%c%c        %c%c%c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c", i, j, i, j, i, j, i, j, i, j, i, j, i, j);
		printf("         %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(12);
		gotoxy(2, 3);
		printf("     %c%c     %c%c    %c%c %c%c    ", i, j, i, j, i, j, i, j);
		printf("%c%c %c%c      %c%c %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c        %c%c %c%c", i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);
		
		Sleep(70);
		
		Set_Color(4);
		gotoxy(2, 4);
		printf("    %c%c            %c%c %c%c    ", i, j, i, j, i, j);
		printf("%c%c %c%c     %c%c  %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c     %c%c%c%c  %c%c", i, j, i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);
		
		Sleep(70);
		
		Set_Color(4);
		gotoxy(2, 5);
		printf("   %c%c            %c%c    %c%c  ", i, j, i, j, i, j);
		printf("%c%c  %c%c    %c%c  %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c   %c%c%c%c    %c%c", i, j, i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);

// 5	
		Sleep(70);
		
		Set_Color(14);
		gotoxy(2, 6);
		printf("  %c%c     %c%c%c%c%c%c  %c%c%c%c%c%c%c%c  ", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);
		printf("%c%c  %c%c   %c%c   %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c %c%c%c%c      %c%c", i, j, i, j, i, j, i, j);
		printf("         %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(14);
		gotoxy(2, 7);
		printf("   %c%c       %c%c  %c%c     %c%c  ", i, j, i, j, i, j, i, j);
		printf("%c%c   %c%c  %c%c   %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c   %c%c%c%c    %c%c", i, j, i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);
		
		Sleep(70);
		
		Set_Color(10);
		gotoxy(2, 8);
		printf("    %c%c     %c%c  %c%c      %c%c  ", i, j, i, j, i, j, i, j);
		printf("%c%c   %c%c %c%c    %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c     %c%c%c%c  %c%c", i, j, i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);
		
		Sleep(70);
		
		Set_Color(10);
		gotoxy(2, 9);
		printf("     %c%c   %c%c   %c%c       %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
		printf("%c%c        %c%c %c%c", i, j, i, j, i, j);
		printf("         %c%c       \n", i, j);

// 9	
		Sleep(70);
		
		Set_Color(9);
		gotoxy(2, 10);
		printf("      %c%c%c%c%c%c  %c%c        %c%c ", i, j, i, j, i, j, i, j, i, j);
		printf("%c%c     %c%c     %c%c ", i, j, i, j, i, j);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c ", i, j, i, j, i, j, i, j, i, j, i, j);
		printf("%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);
	
// Town
// 11	
		Sleep(70);
		
		Set_Color(9);
		gotoxy(2, 12);
		printf("   %c%c%c%c%c%c%c%c%c%c%c%c      %c%c %c%c          ", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);
		printf("           %c%c      %c%c      %c%c", i, j, i, j, i, j);
		printf("   %c%c%c%c    %c%c\n", i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(1);
		gotoxy(2, 13);
		printf("        %c%c         %c%c     %c%c        ", i, j, i, j, i, j);
		printf("            %c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
		printf("   %c%c %c%c   %c%c\n", i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(1);
		gotoxy(2, 14);
		printf("        %c%c        %c%c       %c%c       ", i, j, i, j, i, j);
		printf("            %c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
		printf("   %c%c %c%c   %c%c\n", i, j, i, j, i, j);

// 14	
		Sleep(70);
		
		Set_Color(11);
		gotoxy(2, 15);
		printf("        %c%c       %c%c         %c%c       ", i, j, i, j, i, j);
		printf("            %c%c  %c%c  %c%c  %c%c  ", i, j, i, j, i, j, i, j);
		printf("   %c%c  %c%c  %c%c\n", i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(11);
		gotoxy(2, 16);
		printf("        %c%c        %c%c       %c%c       ", i, j, i, j, i, j);
		printf("             %c%c  %c%c  %c%c  %c%c  ", i, j, i, j, i, j, i, j);
		printf("   %c%c   %c%c %c%c\n", i, j, i, j, i, j);
		
		Sleep(70);
		
		Set_Color(13);
		gotoxy(2, 17);
		printf("        %c%c         %c%c     %c%c        ", i, j, i, j, i, j);
		printf("              %c%c%c%c    %c%c%c%c   ", i, j, i, j, i, j, i, j);
		printf("   %c%c   %c%c %c%c\n", i, j, i, j, i, j);

// 17	
		Sleep(70);
		
		Set_Color(13);
		gotoxy(2, 18);
		printf("        %c%c           %c%c %c%c          ", i, j, i, j, i, j);
		printf("               %c%c      %c%c    ", i, j, i, j);
		printf("   %c%c    %c%c%c%c\n", i, j, i, j, i, j);
	
	
		Set_Color(15);
		Sleep(300);
		gotoxy(30, 23);
		printf("����Ű�� �����̽���(����)�� ���� !");
	}

	void Status()
	{
		gotoxy(88, 1);printf("%d�� °\n", Day);
		
		gotoxy(88, 3);printf("                         ");
		gotoxy(88, 3);printf("���� ���� %.2lf �� ��", Money);
		
		gotoxy(88, 4);printf("HP : %d     ", HP);
		
		gotoxy(88, 5);printf("�ݱ� %d�� ������", Gold_Have);
	}
	
	void Map_1_Draw()
	{
		int i = 0xa1;
		int j = 0xac;
		
//�� ��	
		gotoxy(2, 2);
		i = 0xa1, j = 0xac;
		printf("    ________            ________                ________           ________ ");
		gotoxy(2, 3);
		printf("   /        %c%c         /        %c%c             /        %c%c        /        %c%c    ", i, j, i, j, i, j, i, j);
		gotoxy(2, 4);
		printf("  /           %c%c      /           %c%c          /           %c%c     /           %c%c  ", i, j, i, j, i, j, i, j);
		gotoxy(2, 5);
		printf(" /              %c%c   /              %c%c       /              %c%c  /              %c%c", i, j, i, j, i, j, i, j);
		gotoxy(2, 6);
		printf(" |    ��Ŀ��     |   |   ���ǹ�      |       |   �� �ŷ���   |  |     �渶��    |");
		gotoxy(2, 7);
		printf(" |               |   |               |       |               |  |               |");
		gotoxy(2, 8);
		i = 0xa2, j = 0xc6;
		printf(" |______%c%c_______|   |______%c%c_______|       |______%c%c_______|  |_______%c%c______|", i, j, i, j, i, j, i, j);
		gotoxy(2, 9);
		i = 0xa1, j = 0xd9;
		printf("        %c%c                  %c%c                      %c%c                  %c%c", i, j, i, j, i, j, i, j);
		
//�Ʒ� ��
		gotoxy(2, 12);
		printf("  ______%c%c_______     ______%c%c_______         ______%c%c_______    _______%c%c______", i, j, i, j, i, j, i, j);
		gotoxy(2, 13);
		i = 0xa2, j = 0xc6;
		printf(" |      %c%c       |   |      %c%c       |       |      %c%c       |  |       %c%c      |", i, j, i, j, i, j, i, j);
		gotoxy(2, 14);
		printf(" |               |   |               |       |               |  |               |");
		gotoxy(2, 15);
		printf(" |      ȣ��     |   |        ��     |       |     �ε���    |  |   ��� �ȱ�   |");
		gotoxy(2, 16);
		i = 0xa1, j = 0xac;
		printf(" %c%c              /   %c%c              /       %c%c              /  %c%c              /", i, j, i, j, i, j, i, j);
		gotoxy(2, 17);
		printf("   %c%c           /      %c%c           /          %c%c           /     %c%c           /", i, j, i, j, i, j, i, j);
		gotoxy(2, 18);
		printf("     %c%c________/         %c%c________/             %c%c________/        %c%c________/", i, j, i, j, i, j, i, j);
	
		gotoxy(1, 0);
		printf("Map 1");
	}
	
	void Big_Clear()
	{
		gotoxy(2, 1);printf("                                                                                  ");
		gotoxy(2, 2);printf("                                                                                  ");
		gotoxy(2, 3);printf("                                                                                  ");
		gotoxy(2, 4);printf("                                                                                  ");
		gotoxy(2, 5);printf("                                                                                  ");
		gotoxy(2, 6);printf("                                                                                  ");
		gotoxy(2, 7);printf("                                                                                  ");
		gotoxy(2, 8);printf("                                                                                  ");
		gotoxy(2, 9);printf("                                                                                  ");
		gotoxy(2, 10);printf("                                                                                  ");
		gotoxy(2, 11);printf("                                                                                  ");
		gotoxy(2, 12);printf("                                                                                  ");
		gotoxy(2, 13);printf("                                                                                  ");
		gotoxy(2, 14);printf("                                                                                  ");
		gotoxy(2, 15);printf("                                                                                  ");
		gotoxy(2, 16);printf("                                                                                  ");
		gotoxy(2, 17);printf("                                                                                  ");
		gotoxy(2, 18);printf("                                                                                  ");
		gotoxy(2, 19);printf("                                                                                  ");
	}
	
	void Long_Clear()
	{
		gotoxy(2, 21);printf("                                                                                  ");
		gotoxy(2, 22);printf("                                                                                  ");
		gotoxy(2, 23);printf("                                                                                  ");
		gotoxy(2, 24);printf("                                                                                  ");
		gotoxy(2, 25);printf("                                                                                  ");
	}
	
	void Small_Clear()
	{
		gotoxy(90, 21);printf("                ");
		gotoxy(90, 22);printf("                ");
		gotoxy(90, 23);printf("                ");
		gotoxy(90, 24);printf("                ");
		gotoxy(90, 25);printf("                ");
	}
	
	void Loading_Clear()
	{
		gotoxy(2, 27);printf("                                                                                  ");
	}
	
	void Full_Clear()
	{
		Big_Clear();
		Long_Clear();
		Small_Clear();
		Loading_Clear();
		Status();
	}
	
	void Set_Color(int Text)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Text | 0);
	}
	
	
	
// ����
	int main()							// ���� �Լ�
	{
		int M_S;
		int Map = 1;
		int Map_1[21][43] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // ��
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1},
		{1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // Ȧ
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // Ȧ
		{1,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,0,0,0,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1},
		{1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // ��
		};
		
		int i, j;
		
		float Gold_Price = 1000;
		int Gold_B = 0;
		
		int x = 42;
		int y = 11;
		
		int Move;
		int Select;
		int Day_f = 1;
		
		srand(time(NULL));	
		
		Set_Color(15);				// �۾� �� ���

		system("mode con cols=115 lines=30");	// ȭ�� ũ�� ����
	
		system("cls");
		Edge();
		
		First_Menu();					// ���� �޴����� ���� ���� ���� ����
		
		
		while(1)
		{	
			Day_f = 1;
			
			Full_Clear();
			
			if(0 < Gold_B && Gold_B < 3)				// �ݱ� ������
			{
				gotoxy(3, 24);
				printf("�ݱ��� ���� �����ϴ� ���Դϴ�!!\n\n");
			}
			if(Gold_B == 10)
			{
				gotoxy(3, 24);
				printf("�ݱ��� ���� ���ڱ� �پ����ϴ�!!!\n\n");
				Gold_B = 0;
			}
			
			if(Map == 1)				// �� 1�� �� ȭ�� �׸���
			{
				i = 0xa1, j = 0xd9;
				gotoxy(40, 0);			// ��
				printf("%c%c%c%c%c%c", i, j, i, j, i, j);
				gotoxy(40, 20);
				printf("      ", i, j, i, j, i, j);
				Map_1_Draw();
			}
			
			M_S = 0;					// �޴� �ʱ�ȭ
			
			gotoxy(x, y);
			printf("%c%c", 0xa1, 0xdc);
			
			while(M_S == 0)				// �޴� �ν�
			{
				Status();
				
				gotoxy(0, 28);
				Move = getch();
				
				if(Move == 27)				// ESC �Է½� ����
					exit(0);
				
				if(Move == 224)				// ����Ű �ν�
				{
					Move = getch();
					gotoxy(x, y);			// �����
					printf("  ");
					
					switch(Move)
					{
						case 72:			// ��
							if(Map == 1)
							{
								if(Map_1[y-1][x/2] != 1)
									y -= 1;
							}
							break;
						
						case 75:			// ����
							if(Map == 1)
							{
								if(Map_1[y][(x/2)-1] != 1)
									x -= 2;
							}
							break;
						
						case 77:			// ������
							if(Map == 1)
							{
								if(Map_1[y][(x/2)+1] != 1)
									x += 2;
							}
							break;
						
						case 80:			// �Ʒ�
							if(Map == 1)
							{
								if(Map_1[y+1][x/2] != 1)
									y += 1;
							}
							break;
							
						default:
							break;
					}
				}
				
				gotoxy(x, y);
				printf("%c%c", 0xa1, 0xdc);
				gotoxy(90, 10);
				printf("x = %2d", x/2);
				gotoxy(90, 11);
				printf("y = %2d", y);
				
				if(20 <= x/2 && x/2 <= 22 && y == 0)				// �� �� ���
				{
					if(Map == 1)
					{
						gotoxy(3, 22);
						printf("������ ���� ������ �����Ͻðڽ��ϱ�?");
						
						i = YN();
						
						if(i == 1)
							exit(0);
						
						if(i == 2)
						{
							Long_Clear();
							y += 2;
							
							i = 0xa1, j = 0xd9;
								
							gotoxy(40, 0);			// ��
							printf("%c%c%c%c%c%c", i, j, i, j, i, j);
							
							gotoxy(x, y);
							printf("%c%c", 0xa1, 0xdc);
						}
					}
					
					
				}
				
				if(x/2 == 5 && y == 9)
					M_S = 1;
				
				if(x/2 == 15 && y == 9)
					M_S = 2;
				
				if(x/2 == 27 && y == 9)
					M_S = 3;
				
				if(x/2 == 37 && y == 9)
					M_S = 4;
				
				if(x/2 == 5 && y == 12)
					M_S = 5;
				
				if(x/2 == 15 && y == 12)
					M_S = 6;
				
				if(x/2 == 27 && y == 12)
					M_S = 7;
				
				if(x/2 == 37 && y == 12)
					M_S = 8;
				
				if(x/2 == 1 && y == 18)
					M_S = 66;
				
				if(x/2 == 1 && y == 19)
					M_S = 77;
				
			//	gotoxy(90, 13);
			//	printf("M_S = %d", M_S);
			}
			
			if(Map == 1)
			{
				gotoxy(2, 21);
				switch(M_S)
				{
					case 1:														// ��Ŀ��
						if(Money < 1)
						{
							printf("���� �ּ� �ݾ׺��� ���� �ݾ��� ���� ������ �� �����ϴ�.");
							ing(1);
							break;
						}
						
						printf("��Ŀ�濡 �����մϴ�.");
						ing(1);
						Poker_Room();
						
						y += 1;
						break;
						
					case 2:
						if(Money < 10)
						{
							printf("�ζ� ���ݺ��� ���� �ݾ��� ���� ������ �� �����ϴ�.");	// ���ǹ�
							ing(1);
							break;
						}
						printf("���ǹ濡 �����մϴ�.");
						ing(1);
						Lottery();
						
						y += 1;
						break;
						
					case 3:
						printf("�� �ŷ��ҿ� �����մϴ�.");
						ing(1);
						Gold_Store(Gold_Price, &Gold_Have);
						
						y += 1;
						break;
						
					case 4:
						if(Money < 1)
							{
								printf("���� �ּ� �ݾ׺��� ���� �ݾ��� ���� ������ �� �����ϴ�.");
								ing(1);
								break;
							}
						printf("�渶�忡 �����մϴ�.");
						ing(1);
						Race();
						
						y += 1;
						break;
						
					case 5:														// ȣ��
						if(Money < 100)
						{
							printf("ȣ�� ��뺸�� ���� �ݾ��� ���� ������ �� �����ϴ�.");
							ing(1);
							break;
						}
						printf("ȣ�ڿ� �����մϴ�.");
						ing(1);
						Hotel();
						
						y -= 1;
						break;
							
					case 6:
						if(House_Have == 0)
						{
							printf("���� ���� �������� �ʾҽ��ϴ�.");
							Day_f = 2;
							ing(1);
						}
						
						if(House_Have == 1)
						{
							printf("���� �����մϴ�.");
							ing(1);
							House();
						}
						
						y -= 1;
						break;
					case 7:
						printf("�ε��꿡 �����մϴ�.");
						ing(1);
						Real_Estate();
						
						y -= 1;
						break;
						
					case 8:														// ���
						if(Money < 100)
						{
							HP += 50;
							if(HP > (100 + (Drink * 30)))
								HP = 100 + (Drink * 30);
							Money += 100;
							printf("�ǻ簡 ������ ���鼭 HP�� ȸ�������־����ϴ�\n");
							printf("�ҹ����� ������ �Ⱦ� 100�� ���� ������ϴ�.");
						}
						else 
						{
							printf("���� ���� ���� ã�ư��ô�.");
							Day_f = 2;
						}
						ing(1);
						
						y -= 1;
						break;
						
					case 9:
						printf("���۰��Կ� �����մϴ�.");
						ing(1);
						Hole();
						
						break;
						
					case 10:
						printf("���� �������� Ȯ�����Դϴ�.");
						ing(1);
						Item_Check();
						Day_f = 2;
						break;
						
					case 11:
						printf("���࿡ �����մϴ�.");
						ing(1);
						Bank();
						break;
					
					case 55:
						HP -= 20;
						if(HP < 0)
							HP = 0;
						Day_f = 2;
						break;
						
					case 66:
						Money += 1000;
						Day_f = 2;
						break;
						
					case 77:
						break;
						
					case 99:														// ���� ����
						printf("������ �����մϴ�.");
						ing(1);
						exit(0);
					
					default:
						Day_f = 2;
				}
			}

			/*			printf("1. ��Ŀ��\n");
			printf("2. �Ｎ ����\n");
			printf("3. �� �ŷ���\n");
			printf("4. �渶��\n");
			printf("5. ȣ��\n");
			printf("6. ��\n");
			printf("7. �ε���\n");
			printf("8. ��� �ȱ�\n");
			printf("9. ���۰���\n");
			printf("10. ���� ������ Ȯ��\n");
			printf("11. ����\n");
//Test		printf("55. �׽�Ʈ HP ���\n");
//Test		printf("66. �׽�Ʈ �� ����\n");
//Test		printf("77. �׽�Ʈ ��¥ ����\n");
			printf("99. ���� ������\n");
			
			gotoxy(0, 22);
			printf("\nChoice : ");
			scanf("%d", &M_S); */
			
			printf("\n\n");
			
			
			if(HP == 0 && Whistle != 0)						// ȣ���� ���
			{
				system("cls");
				
				printf("HP�� 0�Դϴ�..\n");
				printf("��Ʋ�Ÿ��鼭 �ɾ�ٰ� ���и� �������ϴ�.");
				ing(2);
				printf("\n\n\nȣ���⸦ �ҷ� ������ û�մϴ�.");
				ing(3);
				i = rand() % 5 + 1;

				if(i <= 4)
				{
					printf("\n\n'�̺� �ű� ����!'\n");
					printf("������� ���־����ϴ�.\n");
					printf("���а� ȣ�ٴ� �������ϴ�.\n");
					ing(3);
				}
				else
				{
					printf("\n\n�ƹ��� ���� �ʾҽ��ϴ�...\n");
					printf("���п��� ���� ���Ѱ���ϴ�\n");
					
					
					if(Money > 200)
					{
						i = (Money / 2);
						printf("- %d�� ��....\n", i);
						Money -= i;
					}
					else if(Money >= 100)
					{
						printf("- 100�� ��....\n");
						Money -= 100;
					}
					else
					{
						printf("- %.2lf�� ��....\n");
						Money = 0;
					}
					ing(2);
				}
				Whistle --;
				HP = 10;
				
			}
			if(HP == 0)										// HP 0
			{
				system("cls");
				printf("HP�� 0�Դϴ�..\n");
				Sleep(1500);
				printf("��Ʋ�Ÿ��鼭 �ɾ�ٰ� �������� ���� ���Ѱ���ϴ�..\n");
				Sleep(1500);
				
				if(Money > 200)
				{
					i = (Money / 2);
					printf("- %d�� ��....\n", i);
					Money -= i;
				}
				else if(Money >= 100)
				{
					printf("- 100�� ��....\n");
					Money -= 100;
				}
				else
				{
					printf("- %.2lf�� ��....\n");
					Money = 0;
				}
				
				ing(2);
				HP = 10;
			}
				
			int Bank_Storage_Main = 0;						// ������ �ݾ�
			for(i = 1; i <= 9; i++)
			{
				if(Saving[i] == 1)
					Bank_Storage_Main += Ten_Square(i);
			}
				
				
			if(Day_f == 1)												// �ǹ��� ���ٰ� ������ �Ϸ� ����
			{
				Day++;													
				Gold_Change(&Gold_Price, &Gold_B);					// �ݰ� ����
				Money += (Bank_Storage_Main / 10);						// ���� �߰�
			}
		}
		
		return 0;
	}

	
// �ʱ� �޴�	
	void First_Menu()					// �޴�
	{
		int i = 1;					// �޴� ����
		int key= 0;					// Ű �ν�
		
		while(1)
		{
			system("cls");
			Edge();
			Title();
			
			gotoxy(38, 14);
			printf("���� %c%c", 0xa1, 0xdb);
			gotoxy(38, 15);
			printf("���� %c%c", 0xa1, 0xdb);
			gotoxy(38, 16);
			printf("���� %c%c", 0xa1, 0xdb);
			
			while(1)
			{
				gotoxy(44, 13 + i);
				printf("\b%c%c", 0xa1, 0xdc);
				
				gotoxy(0, 28);
				key = getch();
				if(key == 224)
				{
					key = getch();
					gotoxy(44, 13 + i);
					printf("\b%c%c", 0xa1, 0xdb);
					switch(key)
					{
						case 72:
							if(i > 1)
								i--;
							
							break;
						
						case 80:
							if(i < 3)
								i++;
						
							break;
							
						default:
							break;
					}
				}
				
				if(key == 32 || key == 13)
					break;
			}
			
			if(i == 1)
			{
				ing(1);
				break;
			}
			
			if(i == 2)
			{
				ing(0.5);
				First_inf();
			}
			
			if(i == 3)
			{
				ing(0.3);
				exit(0);
			}
		}
	}
	
	void First_inf()					// �ʱ� ����
	{
		int Page = 1;
		int key;
		int Change = 1;
		
		system("cls");
		Edge();
		
		gotoxy(30, 22);
		printf("%c%c %c%c�� ������ �ѱ��", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("�����̽� ��, ���� Ű�� �������� ���ư���");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
				
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�׺� Ÿ���� ���� ������ �湮�ϴ� �����Դϴ�.");
					gotoxy(3,3);
					printf("���� ���� ���Ӱ� ���� �ü����� ������ �� �ֽ��ϴ�.");
					
					int i = 0xa1;
					gotoxy(3,5);
					printf("%c%c %c%c %c%c %c%c ����Ű�� �̿��� ���� ���ƴٴ� �� ������", i,0xe8, i,0xe9, i,0xe7, i,0xe6);
					gotoxy(3,6);
					printf("�����̽��� �� ���͸� ���� �޴��� �� �� �ֽ��ϴ�.");
					gotoxy(3,7);
					printf("���� �ǹ��� �հ� �ٴ� �� ������");
					gotoxy(3,8);
					printf("�ǹ� ���� ������ ���� �ǹ��� ������ �� �ֽ��ϴ�.");
					
					gotoxy(3,10);
					printf("ù ��° ���� ���� ���� ������ ���� �� ������");
					gotoxy(3,11);
					printf("             �Ʒ��� ���� �� ��° ������ �̵��մϴ�.");
					gotoxy(3,13);
					printf("�� ��° �ʿ��� ���� ���� ù ��° ������ �̵��ϸ�");
					gotoxy(3,14);
					printf("               �Ʒ��� ���� �� ��° ������ �̵��ϴ� ������ �̷���� �ֽ��ϴ�.");
					
					gotoxy(3,18);
					printf("���ӵ��� �⺻���� ������ �ǹ� �ȿ� �� Ȯ���� �� �ֽ��ϴ�.");
					
					gotoxy(75,19);
					printf("Page 1/3");
				}
					
				if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�ǹ��� ���ٰ� ���� ������ �Ϸ簡 �귯���ϴ�.");
					gotoxy(3,3);
					printf("�ֽİ� �ݱ��� ������ �Ϸ縶�� �����մϴ�.");
					
					gotoxy(3,5);
					printf("������ �Ϸ翡 10%%�� ���ڰ� ����ϴ�.");
					
					gotoxy(3,7);
					printf("���� ���� �ൿ�� �� ������ HP�� �����ϴµ�");
					gotoxy(3,8);
					printf("HP�� 0�� �Ǹ� ���п��� ���� ���ѱ�ϴ�.");
					gotoxy(3,9);
					printf("���ѱ�� ���� �⺻������ 100�� ���̸�");
					gotoxy(3,10);
					printf("���� �ݾ��� 200�� ���� �Ѿ ��� ������ ���ѱ�ϴ�.");
					
					gotoxy(3,12);
					printf("ȣ���̳� ������ �޽��� HP�� ä�� �� �ֽ��ϴ�.");
					
					gotoxy(3,14);
					printf("���۰��Կ��� �÷��̿� ������ �Ǵ� ���� �������� ������ �� �ֽ��ϴ�");
					
					gotoxy(3,16);
					printf("���� ���� �� �������� ��� ��⸦ �Ⱦ� �⺻ �ڱ��� �ٽ� ������ �� �ֽ��ϴ�.");
			
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("Page 3�� ���� ���� ��");
					gotoxy(3,3);
					printf("�� �߰��� �� ����");
					
					gotoxy(75,19);
					printf("Page 3/3");
				}
			}
			gotoxy(0, 28);
			key = getch();
			if(key == 224)
			{
				key = getch();
				if(key == 75)
				{
					if(1 < Page && Page <= 3)
					{
						Page--;
						Change = 1;
					}
				}
				if(key == 77)
				{
					if(1 <= Page && Page < 3)
					{
						Page++;
						Change = 1;
					}
				}
			}
			
			if(key == 32 || key == 13)
				break;
		}
		ing(0.5);
	}
	
	
	
// ���� �˰���
	int YN()							// Yes or No
	{
		int i = 1;
		int key;
		
		int A;
		
		gotoxy(91, 23);
		printf("Yes      No %c%c", 0xa1, 0xdb);
			
		while(1)
		{
			gotoxy(88 + i * 8, 23);
			printf("\b%c%c", 0xa1, 0xdc);
			gotoxy(2, 21);
			
			gotoxy(0, 28);
			key = getch();
			if(key == 224)
			{
				key = getch();
				gotoxy(88 + i * 8, 23);
				printf("\b%c%c", 0xa1, 0xdb);
				switch(key)
				{
					case 75:
						if(i == 2)
							i--;
						
						break;
					
					case 77:
						if(i == 1)
							i++;
					
							break;
						
					default:
						break;
				}
			}
			
			if(key == 32 || key == 13)
				break;
		}
		
		return i;
	}
	
	void ing(float n)						// �ε� (n * 1 ��)
	{
		int i;
		gotoxy(2, 27);
		for(i = 1; i <= 41; i++)
		{
			printf("%c%c", 0xa1, 0xe1);
			Sleep(25 * n);
		}
	}
	
	void gotoxy(int x, int y)			// gotoxy
	{
		COORD Pos;
		Pos.X = x;
		Pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
	}

	int Ten_Square(int num)
	{
		int i;
		int TEN = 1;
		
		for(i = 1; i <= num; i++)
			TEN = (TEN * 10);
		
		return TEN;
	}
	
	int Ten_Divide(int num)
	{
		int i;
		
		for(i = 0; 1 < num; i++)
			num = (num / 10);
		
		return i;
	}
	
	
	
// ����
	// ��Ŀ �Լ�
	void Poker_Room()
	{
		
		
		int i = 1;					// �޴� ����
		int key= 0;					// Ű �ν�
		int re = 0;
		int time = 0;
		int up = -1;
		int j = 0;
		
		
		int Number, Type;
		
		while(re < 2)
		{
			Full_Clear();
			
			if(re == 0)
			{
				gotoxy(3, 22);printf("��Ŀ�濡 �����Ͽ����ϴ�.");
			}
			
			if(re == 1)
			{
				gotoxy(3, 22);printf("��Ŀ�� Ȧ�� ���ƿԽ��ϴ�.");
			}
			
			Sleep(500);
			gotoxy(35, 23);printf("%c%c %c%c �� �̵� , �����̽���(����)�� ����", 0xa1,0xe8, 0xa1,0xe9);
			gotoxy(3, 24);printf("������ �Ͻðڽ��ϱ�?");
			
			
			gotoxy(24, 14);
			printf("���̺� ��ο� ��Ŀ %c%c", 0xa1, 0xdb);
			gotoxy(33, 15);
			printf("���� ��Ŀ %c%c", 0xa1, 0xdb);
			gotoxy(38, 16);
			printf("���� %c%c", 0xa1, 0xdb);
			gotoxy(36, 17);
			printf("������ %c%c", 0xa1, 0xdb);
			
			gotoxy(3, 10);printf("���������������� ");
			gotoxy(3, 11);printf("�� ?    �� ");
			gotoxy(3, 12);printf("��      �� ");
			gotoxy(3, 13);printf("��      �� ");
			gotoxy(3, 14);printf("��   ?  �� ");
			gotoxy(3, 15);printf("��      �� ");
			gotoxy(3, 16);printf("��      �� ");
			gotoxy(3, 17);printf("��     ?�� ");
			gotoxy(3, 18);printf("���������������� ");
			
			gotoxy(13, 10);printf("���������������� ");
			gotoxy(13, 11);printf("�� ?    �� ");
			gotoxy(13, 12);printf("��      �� ");
			gotoxy(13, 13);printf("��      �� ");
			gotoxy(13, 14);printf("��   ?  �� ");
			gotoxy(13, 15);printf("��      �� ");
			gotoxy(13, 16);printf("��      �� ");
			gotoxy(13, 17);printf("��     ?�� ");
			gotoxy(13, 18);printf("���������������� ");
			
			while(1)
			{
				gotoxy(44, 13 + i);
				printf("\b%c%c", 0xa1, 0xdc);
				
				gotoxy(0, 28);
				if(kbhit())
				{
					gotoxy(0, 28);key = getch();
					if(key == 224)
					{
						key = getch();
						gotoxy(44, 13 + i);
						printf("\b%c%c", 0xa1, 0xdb);
						switch(key)
						{
							case 72:
								if(i > 1)
									i--;
								break;
							
							case 80:
								if(i < 4)
									i++;
								break;
								
							default:
								break;
						}
					}
					if(key == 32 || key == 13)
						break;
				}
				else
				{
					time++;
					

					if(time == 300)
					{
						Number = rand() % 14 + 1;
						Type = rand() % 4 + 1;
						Show(15, 11, Number, Type, 1);
					}
					
					if(time == 1300)
					{
						Number = rand() % 14 + 1;
						Type = rand() % 4 + 1;
						Show(5, 11, Number, Type, 1);
					}

					if(time % 100 == 0)
					{
						gotoxy(73 - j, 2); printf("���������������� ");
						gotoxy(73 - j, 3); printf("�� ?    �� ");
						gotoxy(73 - j, 4);printf("��      �� ");
						gotoxy(73 - j, 5);printf("��   ?  �� ");
						gotoxy(73 - j, 6);printf("��      �� ");
						gotoxy(73 - j, 7);printf("��     ?�� ");
						gotoxy(73 - j, 8);printf("���������������� ");
						
						j++;
						
						if(j == 35 && up == -1)
							up = 0;
						if(j > 70)
						{
							j = 0;
							
							Number = rand() % 14 + 1;
							Type = rand() % 4 + 1;
							Show(5, 3, Number, Type, 0);
							
						}
					}
					
					if(up >= 0 && time %100 == 0)
					{
						gotoxy(73 - up, 2); printf("���������������� ");
						gotoxy(73 - up, 3); printf("�� ?    �� ");
						gotoxy(73 - up, 4);printf("��      �� ");
						gotoxy(73 - up, 5);printf("��   ?  �� ");
						gotoxy(73 - up, 6);printf("��      �� ");
						gotoxy(73 - up, 7);printf("��     ?�� ");
						gotoxy(73 - up, 8);printf("���������������� ");
						
						up++;
						
						if(up > 70)
						{
							up = 0;
							
							Number = rand() % 14 + 1;
							Type = rand() % 4 + 1;
							Show(5, 3, Number, Type, 0);
							
						}
					}
					
					
					
					
					
					
					if(time == 2000)
						time = 0;
				}
			}
			
			switch(i)					// �޴��� ���� �̵�
			{
				case 1:
					ing(1);
					Poker_Five_Draw_1();
					re = 1;
					break;
					
				case 2:
					ing(1);
					re = 1;
					break;
				
				case 3:
					ing(0.5);
					Poker_Room_inf();
					break;
				
				case 4:
					Long_Clear();
					gotoxy(3, 22);printf("��Ŀ�濡�� �����մϴ�.");
					ing(0.3);
					re = 2;
					break;
			}
		}
	}

	void Show(int x, int y, int N, int T, int i)
	{
		gotoxy(x, y);				// �� ���� ���
		if(T == 1)
			printf("%c%c", 0xa2, 0xbc);
		else if(T == 2)
		{
			Set_Color(12);
			printf("%c%c", 0xa2, 0xbe);
		}
		else if(T == 3)
		{
			Set_Color(12);
			printf("%c%c", 0xa1, 0xdf);
		}
		else if(T == 4)
			printf("%c%c", 0xa2, 0xc0);
		
		gotoxy(x + 3, y + 4 + i + i);			// �Ʒ� ���� ���
		if(T == 1)
			printf("%c%c", 0xa2, 0xbc);
		else if(T == 2)
			printf("%c%c", 0xa2, 0xbe);
		else if(T == 3)
			printf("%c%c", 0xa1, 0xdf);
		else if(T == 4)
			printf("%c%c", 0xa2, 0xc0);
		
		gotoxy(x + 2, y + 2 + i);					// ����
		if(N <= 10)
		{
			gotoxy(x + 2, y + 2 + i);
			printf("%2d", N);
		}
		else if(N == 11)
			printf(" J");
		else if(N == 12)
			printf(" Q");
		else if(N == 13)
			printf(" K");
		else if(N == 14)
			printf(" A");
		
		Set_Color(15);
	}
	
	void Poker_Room_inf()
	{
		int Page = 1;
		int key;
		int Change = 1;
		
		Full_Clear();
			
		gotoxy(30, 22);
		printf("%c%c %c%c�� ������ �ѱ��", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("�����̽� ��, ���� Ű�� �������� ���ư���");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
			
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("��Ŀ�濡���� �پ��� ��Ģ�� ��Ŀ ������ �� �� �ֽ��ϴ�.");
					gotoxy(3,4);
					printf("����Ű�� �����̽� ��(����)�� ����մϴ�.");
					
					gotoxy(3,6);
					printf("���̺� ��ο� ��Ŀ�� ȥ�ڼ� ������ �и� ���� ������ �ϴ� 1�ο��");
					gotoxy(3,7);
					printf("                     ������ �и� ���� ������ �ϴ� 2�ο��� �ֽ��ϴ�.");
					
					
					gotoxy(3,18);
					printf("��Ŀ ���� �� �Ǵ� HP�� 6�� �����մϴ�.");
					
					gotoxy(75,19);
					printf("Page 1/1");
				}
					
				/*if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�� ������ ������ ���� ������ �����̴� ���� �ʽ��ϴ�.");
					gotoxy(3,3);
					printf("�Ʒ��� �� ������ �����Դϴ�.");
					
					gotoxy(3,5);
					printf("�� ��� : �Ʒ��� ��޵Ǵ� ��� �������� �ش���� �ʴ� ���.");
					gotoxy(3,6);
					printf("          ���� �� ��ŭ ���� �ҽ��ϴ�.");
					gotoxy(3,8);
					printf("�� ��� : ���ڰ� ���� ī�� 2���� ����.");
					gotoxy(3,9);
					printf("          ���� �� �ݾ��� 0.5�踦 �����޽��ϴ�.");
					gotoxy(3,11);
					printf("�� ��� : �� �� 2�� ����.");
					gotoxy(3,12);
					printf("          ���� �� �ݾ��� 0.9�踦 �����޽��ϴ�.");
					gotoxy(3,14);
					printf("Ʈ���� : ���ڰ� ���� ī�� 3���� ����.");
					gotoxy(3,15);
					printf("         ���� �� �ݾ��� 3�踦 ����ϴ�.");
					gotoxy(3,17);
					printf("��Ʈ����Ʈ : ���ڰ� ���ӵ� ī�� 5��.");
					gotoxy(3,18);
					printf("             ���� �� �ݾ��� 20�踦 ����ϴ�.");
					
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�÷��� : ���� ������� ���̰� ���� ī�� 5��.");
					gotoxy(3,3);
					printf("         ���� �� �ݾ��� 8�踦 ����ϴ�.");
					gotoxy(3,5);
					printf("Ǯ �Ͽ콺 : Ʈ���ð� �� �� ���� ����.");
					gotoxy(3,6);
					printf("           ���� �� �ݾ��� 10�踦 ����ϴ�~");
					gotoxy(3,8);
					printf("��ī�� : ���ڰ� ���� ī�� 4��.");
					gotoxy(3,9);
					printf("         ���� �� �ݾ��� 30�踦 ����ϴ� ~~!!");
					
					gotoxy(75,19);
					printf("Page 3/3");
				}*/
			}
			
			gotoxy(0, 28);
			key = getch();
			if(key == 224)
			{
				key = getch();
				if(key == 75)
				{
					if(1 < Page && Page <= 3)
					{
						Page--;
						Change = 1;
					}
				}
				if(key == 77)
				{
					if(1 <= Page && Page < 3)
					{
						Page++;
						Change = 1;
					}
				}
			}
			
			if(key == 32 || key == 13)
				break;
		}
		ing(0.5);
	}
	
	void Poker_Five_Draw_1()							// ���̺� ��ο� ��Ŀ 1
	{
		int Number[6];						// �޴� ī��
		int Type[6];
		
		int i, j, l;
		int key;
		
		int Poker_Count = 1;				// ��Ŀ ī����
		int Poker_re = 1;					// ��Ŀ ��
		
		
		Full_Clear();
		
		gotoxy(3, 22);
		printf("���̺� ��ο� ��Ŀ�� �����մϴ�.");
		
		gotoxy(0, 28);
		Sleep(0);
		
		gotoxy(3, 24);
		printf("������ ���ðڽ��ϱ�?");
			
		i = YN();						// ����
		if(i == 1)
			Poker_Five_Draw_1_inf();
		
		while(Poker_re == 1)			// �ݺ� ����
		{
			int T_Number[6] = {0, 0, 0, 0, 0, 0};		// ���� ī�� �ʱ�ȭ
			int T_Type[6] = {0, 0, 0, 0, 0, 0};
			
			int Card[6] = {0, 0, 0, 0, 0, 0};
			int point = 0;								// ���� �� �� �ʱ�ȭ	
			int Change[6] = {0, 0, 0, 0, 0, 0};			// ü���� �� �� �ʱ�ȭ
			int bet1 = 0;							// ����
			int bet2 = 0;
			
			Full_Clear();
			Status();
			
			for(i = 1 ; i <= 5; i++)			// ó�� ī�� �ޱ�
			{
				for(j = 0; j < 70; j++)
				{
					if(73 - j != 67 - 15 * (5 - i))
					{
						Sleep(6- ((5-i) * 0.5));	// 4
						
						gotoxy(73 - j, 8); printf("���������������� ");
						gotoxy(73 - j, 9); printf("�� ?    �� ");
						gotoxy(73 - j, 10);printf("��      �� ");
						gotoxy(73 - j, 11);printf("��   ?  �� ");
						gotoxy(73 - j, 12);printf("��      �� ");
						gotoxy(73 - j, 13);printf("��     ?�� ");
						gotoxy(73 - j, 14);printf("���������������� ");
					}
					else
						break;
				}
			}
				
			while(1)							// ù ��° ����
			{
				Long_Clear();
				Small_Clear();
				
				gotoxy(3, 21);printf("%d ��° �����Դϴ�.", Poker_Count);
				gotoxy(0, 28);
				Sleep(500);
				gotoxy(3, 23);printf("�󸶸� �����Ͻðڽ��ϱ�?");
				gotoxy(3, 24);printf("  ���� �� (0�̸� ���) ");
				
				gotoxy(70, 22);printf("%c%c %c%c %c%c  1", 0xa1,0xe8, 0xa1,0xe9, 0xa1,0xbe);
				gotoxy(70, 23);printf("%c%c %c%c %c%c 50", 0xa1,0xe7, 0xa1,0xe6, 0xa1,0xbe);
				
				gotoxy(91, 22);printf("����1");
				
				
				while(1)							// ���� Ű �ν�
				{
					gotoxy(97, 22);printf("%d", bet1);
					gotoxy(0, 28);
					key = getch();
					if(key == 224)
					{
						key = getch();
						gotoxy(97, 22);printf("         ");
						
						switch(key)
						{
							case 72:
								if(0 <= bet1 && bet1 < floor(Money))	// floor �� ���� �Լ�
									bet1++;
								break;
								
							case 75:
								if(bet1 <= 50)
									bet1 = 0;
								else if(50 <= bet1 && bet1 <= floor(Money))
									bet1 -= 50;
								break;
								
							case 77:
								if(floor(Money) - 50 < bet1)
									bet1 = floor(Money);
								else if(0 <= bet1 && bet1 <= floor(Money) - 50)
									bet1 += 50;
								break;
							
							case 80:
								if(1 <= bet1 && bet1 <= floor(Money))
									bet1--;
								break;
								
							default:
								break;
						}
					}
					
					if(key == 13 || key == 32)
						break;
				}
				
				Long_Clear();
				if(bet1 == 0)						// ���� ���
				{
					Small_Clear();
					gotoxy(3, 22);
					printf("���̺� ��ο� ��Ŀ�� �׸� �Ͻðڽ��ϱ�?");
					i = YN();
					
						if(i == 1)
							break;							
						if(i == 2)
							continue;
				}
				else
				{
					Money -= bet1;
					Status();
					break;
				}
			}
			
			if(i == 1)
				break;
			
			for(i = 1; i <= 5; i++)					// ī�� �̱�
			{			
				Number[i] = rand() % 9 + 6;
				Type[i] = rand() % 4 + 1;
			
				for(j=1; i-j>0; j++)		// �ߺ� üũ
				{
					if(Number[i] == Number[i-j] && Type[i] == Type[i-j])
						i--;
				}
			}
			
			ShowCard(Number, Type, Change);				// ���� ī�� ���
			for(i = 1; i <= 5; i++)					// Change �� �ʱ�ȭ
				Change[i] = 0;
			
			for(i = 1; i <= 5; i++)					// ī�� �ٲٱ� ���׶�� ���
			{
				gotoxy(12 + 15 * (i-1), 18);printf("%c%c", 0xa1, 0xdb);
				
				gotoxy(79, 16);printf("�Ϸ�");
				gotoxy(80, 18);printf("%c%c", 0xa1, 0xdb);
			}
			
			gotoxy(13, 23);
			printf("%c%c %c%c �� �̿��� �����̰� �����̽��ٳ� ����Ű�� �̿��� ����", 0xa1, 0xe7, 0xa1, 0xe6);
			
			i = 1;
			while(1)							// ī�� �ٲٱ� Ű �ν�
			{
				if(i <= 5)
				{
					gotoxy(13 + 15 * (i-1), 18);printf("\b%c%c", 0xa1, 0xdc);
					gotoxy(2, 21);
				}
				else if(i == 6)
				{
					gotoxy(81, 18);printf("\b%c%c", 0xa1, 0xdc);
				}
				
				gotoxy(0, 28);
				key = getch();
				if(key == 224)
				{
					key = getch();
					if(i <= 5)
					{
						gotoxy(13 + 15 * (i-1), 18);printf("\b%c%c", 0xa1, 0xdb);
					}
					else if(i == 6)
					{
						gotoxy(81, 18);printf("\b%c%c", 0xa1, 0xdb);
					}
					
					switch(key)
					{
						case 75:
							if(1 < i && i <= 6)
								i--;
							break;
						
						case 77:
							if(1 <= i && i < 6)
								i++;
							break;
							
						default:
							break;
					}
				}
				
				if(key == 13 || key == 32)
				{
					if(i <= 5)
					{
						if(Change[i] == 0)
						{
							Change[i] = 1;
							gotoxy(12 + 15 * (i-1), 16);
							printf("%c%c", 0xa1, 0xee);
						}
						else if(Change[i] == 1)
						{
							Change[i] = 0;
							gotoxy(12 + 15 * (i-1), 16);
							printf("  ");
						}
					}
					if(i == 6)
						break;
				}
			}
			
			gotoxy(2, 16);printf("                                                                                  ");
			gotoxy(2, 18);printf("                                                                                  ");			
						
			for(i = 1; i <=5; i++)				// ī�� ������
			{
				if(Change[i] == 1)
				{
					int a, b;
					
					switch(Type[i])
					{
						case 1:
							a = 0xa2; b = 0xbc;
							break;
						
						case 2:
							a = 0xa2; b = 0xbe;
							break;
							
						case 3:
							a = 0xa1; b = 0xdf;
							break;
							
						case 4:
							a = 0xa2; b = 0xc0;	
							break;
					}
					
					for(j = 0; j < 15; j++)
					{
						
						Sleep(20);	// 20
						
						if(15 - j > 0)
						{
							gotoxy(8 + 15 * (i - 1), 15 - j);printf("          ");
							
							
							if(14 - j > 0)
							{
								gotoxy(8 + 15 * (i - 1), 14 - j);printf("���������������� ");
								
								if(13 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), 13 - j);printf("��      �� ");
									
									if(Type[i] == 1 || Type[i] == 4)					// ���� �Ʒ� ����
									{
										gotoxy(14 + 15 * (i - 1), 13 - j);
										printf("%c%c", a,b);
									}
									
									if(Type[i] == 2 || Type[i] == 3)					// ���� �Ʒ� ����
									{
										Set_Color(12);
										
										gotoxy(14 + 15 * (i - 1), 13 - j);
										printf("%c%c", a,b);
										
										Set_Color(15);
									}
									
									if(12 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), 12 - j);printf("��      �� ");
										
										if(11 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), 11 - j);printf("��      �� ");
											
											if(Type[i] == 1 || Type[i] == 4)			// �Ͼ� ���� ���		
											{
												gotoxy(12 + 15 * (i - 1), 11 - j);		
												if(Number[i] <= 10)
													printf("%2d", Number[i]);
												if(Number[i] == 11)
													printf("J");
												if(Number[i] == 12)
													printf("Q");
												if(Number[i] == 13)
													printf("K");
												if(Number[i] == 14)
													printf("A");
											}
											
											if(Type[i] == 2 || Type[i] == 3)			// ���� ���� ���		
											{
												Set_Color(12);
												
												gotoxy(12 + 15 * (i - 1), 11 - j);		
												if(Number[i] <= 10)
													printf("%2d", Number[i]);
												if(Number[i] == 11)
													printf("J");
												if(Number[i] == 12)
													printf("Q");
												if(Number[i] == 13)
													printf("K");
												if(Number[i] == 14)
													printf("A");
												
												Set_Color(15);
											}
											
											if(10 - j > 0)
											{
												gotoxy(8 + 15 * (i - 1), 10 - j);printf("��      �� ");
												
												if(9 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), 9 - j);printf("��      �� ");
													
													if(Type[i] == 1 || Type[i] == 4)	// �Ͼ� �� ����
													{
														gotoxy(10 + 15 * (i - 1), 9 - j);	
														printf("%c%c", a,b);
													}
													if(Type[i] == 2 || Type[i] == 3)	// ���� �� ����
													{
														Set_Color(12);
														
														gotoxy(10 + 15 * (i - 1), 9 - j);	
														printf("%c%c", a,b);
														
														Set_Color(15);
													}
													
													if(8 - j > 0)
													{
														gotoxy(8 + 15 * (i - 1), 8 - j);printf("���������������� ");
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
			for(i = 1; i <= 5; i++)				// ���� �̱�, �ߺ� üũ, ī�� ��������
			{
				
				if(Change[i] == 1)
				{
					int a;
				
					T_Number[i] = Number[i];
					T_Type[i] = Type[i];
				
					do								// ���� �̱�
					{
						a = 0;
						
						Number[i] = rand()% 9 + 6;
						Type[i] = rand() % 4 + 1;	
						
						for(j = 1; j <= 5; j++)
						{
							if(i != j)
							{
								if(Number[i] == Number[j] && Type[i] == Type[j])
									a = 1;
							}
						}
						
						for(j = 1; j <= 5; j++)
						{
							if(Number[i] == T_Number[j] && Type[i] == T_Type[j])	// T
								a = 1;
						}
							
					}while(a!=0);
					
					for(i = 1; i <=5; i++)				// ī�� ��������
					{
						if(Change[i] == 1)
						{
							for(j = 1; j < 15; j++)
							{
								
								Sleep(25);	// 25
								
								if(8 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), j+7);printf("���������������� ");
									
									if(9 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), j+6);printf("��     ?�� ");
										
										if(10 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), j+5);printf("��      �� ");
											
											if(11 - j > 0)
											{
												gotoxy(8 + 15 * (i - 1), j+4);printf("��   ?  ��");
												
												if(12 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), j+3);printf("��      �� ");
													
													if(13 - j > 0)
													{
														gotoxy(8 + 15 * (i - 1), j+2);printf("��?     �� ");
														
														if(14 - j > 0)
														{
															gotoxy(8 + 15 * (i - 1), j+1);printf("���������������� ");
															
															if(15 - j > 0)
															{
																gotoxy(8 + 15 * (i - 1), j);printf("          ");
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}	
			
			while(1)							// �� ��° ����
			{
				Long_Clear();
				
				gotoxy(3, 21);printf("�� ��° ���ýð��Դϴ�.");
				gotoxy(3, 23);printf("�󸶸� �����Ͻðڽ��ϱ�?");
				gotoxy(3, 24);printf("  ���� �� (0�̸� ���) ");
				
				gotoxy(70, 22);printf("%c%c %c%c %c%c  1", 0xa1,0xe8, 0xa1,0xe9, 0xa1,0xbe);
				gotoxy(70, 23);printf("%c%c %c%c %c%c 50", 0xa1,0xe7, 0xa1,0xe6, 0xa1,0xbe);
				
				gotoxy(91, 24);printf("����2");
				
				
				while(1)							// ���� Ű �ν�
				{
					gotoxy(97, 24);printf("%d", bet2);
					gotoxy(0, 28);
					key = getch();
					if(key == 224)
					{
						key = getch();
						gotoxy(97, 24);printf("         ");
						
						switch(key)
						{
							case 72:
								if(0 <= bet2 && bet2 < floor(Money))	// floor �� ���� �Լ�
									bet2++;
								break;
								
							case 75:
								if(bet2 <= 50)
									bet2 = 0;
								else if(50 <= bet2 && bet2 <= floor(Money))
									bet2 -= 50;
								break;
								
							case 77:
								if(floor(Money) - 50 < bet2)
									bet2 = floor(Money);
								else if(0 <= bet2 && bet2 <= floor(Money) - 50)
									bet2 += 50;
								break;
							
							case 80:
								if(1 <= bet2 && bet2 <= floor(Money))
									bet2--;
								break;
								
							default:
								break;
						}
					}
					
					if(key == 13 || key == 32)
						break;
				}
				Money -= bet2;
				Status();
				break;
			}

			ShowCard(Number, Type, Change);	// �ٲ� ī�� ���
			
			// ���� üũ ����
			{
				
				/* if(N[1] == 10 && N[2] == 11 && N[3] == 12 && N[4] == 13 && N[5] == 14)	// �� ��Ʈ����Ʈ
				p += 20; */
				
				if(Type[1] == Type[2] && Type[1] == Type[3] && Type[1] == Type[4] && Type[1] == Type[5]) // �÷���
				{
					Card[1] = 1;
					Card[2] = 1;
					Card[3] = 1;
					Card[4] = 1;
					Card[5] = 1;
					
					point += 10;
				}
				
				{									// ��Ʈ����Ʈ
					for(i = 1; i <= 4; i++)			// �������� ���� ���� ���
					{
						for(j = 1; j <= 5-i; j++)
						{
							if(Number[j] < Number[j+1])
							{
								int t = Number[j];
								Number[j] = Number[j+1];
								Number[j+1] = t;
								
								t = Type[j];
								Type[j] = Type[j+1];
								Type[j+1] = t;
							}
						}
					}
					
					if((Number[1] - 1) == Number[2])	// ���� �۾������� Ȯ��				
					{
						if((Number[2] - 1) == Number[3])
						{
							if((Number[3] - 1) == Number[4])
							{
								if((Number[4] - 1) == Number[5])
								{
									Card[1] = 1;
									Card[2] = 1;
									Card[3] = 1;
									Card[4] = 1;
									Card[5] = 1;
									
									point += 20;
								}
							}
						}
					}
				}
				
				for(i=1; i<=4; i++)	// ��� ���� ~ Ǯ�Ͽ콺
				{
					for(j=1; (i+j)<=5; j++)
					{
						if(Number[i] == Number[i+j])
						{
							Card[i] = 1;
							Card[i+j] = 1;
							point++;
						}
					}
				}
			}
			
			gotoxy(2, 15);printf("                                                                                  ");
			gotoxy(2, 17);printf("                                                                                  ");			
			
			Long_Clear();
			Small_Clear();

			gotoxy(91, 22);printf("���� ���� �ݾ�");
			gotoxy(95, 24);printf("%.2lf", (bet1 + bet2 * 0.8));
			
			i = Card[1] + Card[2] + Card[3] + Card[4] + Card[5];
			gotoxy(0, 28);getch();
			
			if(point != 0)						// ��� â
			{
				{												// ��� ��� â �׸���
					gotoxy(42 - (6 * i) - 1, 6);printf("��");		// �� ��
					for(j = 1; j <= 6 * i; j++)
					{
						printf("��");
					}
					printf("��");
					
					for(j = 7; j <= 15; j++)
					{
						gotoxy(42 - (6 * i) - 1, j);printf("��");
						for(int p = 1; p <= 6 * i; p++)
						{
							printf("  ");
						}
						printf("��");
					}
					
					gotoxy(42 - (6 * i) - 1, 16);printf("��");	// �� �Ʒ�
					for(j = 1; j <= 6 * i; j++)
					{
						printf("��");
					}
					printf("��");
				}
				
				{												// ��� ��� ī��(���)
					l = 1;
					
					for(j = 1; j <= 5; j++)
					{
						if(Card[j] == 1)
						{
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2,  9);printf("���������� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 10);printf("��?     �� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 11);printf("��      �� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 12);printf("��   ?  �� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 13);printf("��      �� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 14);printf("��     ?�� ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 15);printf("���������� ");
							l++;
						}
					}
				}
				
				{												// ��� ��� ī��(����)
					l = 1;
					
					for(j = 1; j <= 5; j++)
					{
						if(Card[j] == 1)
						{
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 4, 10);		// �� ����
							if(Type[j] == 1)
								printf("%c%c", 0xa2, 0xbc);
							else if(Type[j] == 2)
							{
								Set_Color(12);
								printf("%c%c", 0xa2, 0xbe);
							}
							else if(Type[j] == 3)
							{
								Set_Color(12);
								printf("%c%c", 0xa1, 0xdf);
							}
							else if(Type[j] == 4)
								printf("%c%c", 0xa2, 0xc0);
							
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 8, 14);		// �Ʒ� ����
							if(Type[j] == 1)
								printf("%c%c", 0xa2, 0xbc);
							else if(Type[j] == 2)
								printf("%c%c", 0xa2, 0xbe);
							else if(Type[j] == 3)
								printf("%c%c", 0xa1, 0xdf);
							else if(Type[j] == 4)
								printf("%c%c", 0xa2, 0xc0);
							
							
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 7, 12);		// ����
							if(Number[j] <= 10)
								printf("%d", Number[j]);
							else if(Number[j] == 11)
								printf("J");
							else if(Number[j] == 12)
								printf("Q");
							else if(Number[j] == 13)
								printf("K");
							else if(Number[j] == 14)
								printf("A");
							
							l++;
						}
						
						Set_Color(15);
					}
				}
			}
			
			switch(point)						// ���
			{
				case 0:
					gotoxy(3, 22);printf("�� ����Դϴ�.");
					gotoxy(3, 24);printf("���ñ� %d �� ���� �Ҿ����ϴ�.", (bet1 + bet2));
					break;
				
				case 1:
					gotoxy(39, 7);printf("�� ���..");
					gotoxy(3, 22);printf("�� ����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 0.5);
					gotoxy(3, 24);printf("%.2lf �� ���� �����޾ҽ��ϴ�.", ((bet1 + 0.8 * bet2) * 0.5));
					break;
					
				case 2:
					gotoxy(39, 7);printf("�� ���");
					gotoxy(3, 22);printf("�� ����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 0.9);
					gotoxy(3, 24);printf("%.2lf �� ���� �����޾ҽ��ϴ�.", ((bet1 + 0.8 * bet2) * 0.9));
					break;
					
				case 3:
					gotoxy(39, 7);printf("Ʈ����~");
					gotoxy(3, 22);printf("Ʈ�����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 3);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 3.0));
					break;
				
				case 4:
					gotoxy(39, 7);printf("Ǯ �Ͽ콺~~~");
					gotoxy(3, 22);printf("Ǯ �Ͽ콺�Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 10);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 10.0));
					break;
					
				case 13:
					gotoxy(39, 7);printf("Ǯ �Ͽ콺~~~");
					gotoxy(3, 22);printf("Ǯ �Ͽ콺�Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 10);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 10.0));
					break;
					
				case 6:
					gotoxy(39, 7);printf("�� ī��~~!!!!");
					gotoxy(3, 22);printf("�� ī���Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 30);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 30.0));
					break;
					
				case 16:
					gotoxy(39, 7);printf("�� ī��~~!!!!");
					gotoxy(3, 22);printf("�� ī���Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 30);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 30.0));
					break;
					
				case 10:
					gotoxy(39, 7);printf("�÷���~~");
					gotoxy(3, 22);printf("�÷����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 8.0));
					break;
					
				case 11:	
					gotoxy(39, 7);printf("�÷���~~");
					gotoxy(3, 22);printf("�÷����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 8.0));
					break;

				case 12:
					gotoxy(39, 7);printf("�÷���~~");
					gotoxy(3, 22);printf("�÷����Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 8.0));
					break;	
					
				case 20:
					gotoxy(39, 7);printf("��Ʈ����Ʈ~~");
					gotoxy(3, 22);printf("��Ʈ����Ʈ�Դϴ�.");
					Money += (float)((bet1 + 0.8 * bet2) * 20);
					gotoxy(3, 24);printf("%.2lf �� ���� ȹ���߽��ϴ�.", ((bet1 + 0.8 * bet2) * 20.0));
					break;	
			}
			
			gotoxy(0, 28);getch();
			Long_Clear();
			
			if(Money == 0)						// 0��
			{
				gotoxy(3, 21);printf("��Ŀ�濡�� ���� ���� �����̽��ϴ� �Ф�\n");
				Sleep(1000);
				break;
			}
			else if(Money < 1)
			{
				gotoxy(3, 21);printf("���� �ּ� �ݾ׺��� ���� �ݾ��� ���ڶ��ϴ�....\n");
				Sleep(1000);
				break;
			}
			
			HP -= 6;
			if(HP <= 0)							// ü��
			{
				HP = 0;
				gotoxy(3, 21);printf("HP�� 0�� �Ǿ����ϴ�...\n");
				Sleep(1000);
				break;
			}	
			
			Status();
			gotoxy(3, 22);printf("�ٽ� �Ͻðڽ��ϱ�?");
			
			Small_Clear();
			while(1)							// ��
			{
				
				Poker_re = YN();
				if(Poker_re == 1 || Poker_re == 2)
					break;
			}
			
			Poker_Count++;
		}
		
		gotoxy(3, 24);printf("��Ŀ�� ����Ȧ�� ���ư��ϴ�.");
		ing(1);
	}
		
	void ShowCard(int N[], int T[], int C[])	// ī�� ���
	{
		for(int i = 1; i <= 5; i++)
		{
			int a = 0;
			
			Set_Color(15);
			
			if(C[1] == 0 && C[2] == 0 && C[3] == 0 && C[4] == 0 && C[5] == 0)
			{
				C[1] = 1;									// ���� ī�� ��ü ���̸� ���� ���
				C[2] = 1;
				C[3] = 1;
				C[4] = 1;
				C[5] = 1;
			}
			
			if(C[i] == 1)									// ī�� ��ü �Ŀ� ��ü�� ī�常 ���� ���
			{
				gotoxy(10 + 15 * (i-1), 9);				// �� ���� ���
				if(T[i] == 1)
					printf("%c%c", 0xa2, 0xbc);
				else if(T[i] == 2)
				{
					Set_Color(12);
					printf("%c%c", 0xa2, 0xbe);
				}
				else if(T[i] == 3)
				{
					Set_Color(12);
					printf("%c%c", 0xa1, 0xdf);
				}
				else if(T[i] == 4)
					printf("%c%c", 0xa2, 0xc0);
				
				gotoxy(13 + 15 * (i-1), 13);			// �Ʒ� ���� ���
				if(T[i] == 1)
					printf("%c%c", 0xa2, 0xbc);
				else if(T[i] == 2)
					printf("%c%c", 0xa2, 0xbe);
				else if(T[i] == 3)
					printf("%c%c", 0xa1, 0xdf);
				else if(T[i] == 4)
					printf("%c%c", 0xa2, 0xc0);
				
				gotoxy(12 + 15 * (i-1), 11);			// ��ȣ ���
				if(N[i] <= 10)
					printf("\b%2d ", N[i]);
				if(N[i] == 11)
					printf("J ");
				if(N[i] == 12)
					printf("Q ");
				if(N[i] == 13)
					printf("K ");
				if(N[i] == 14)
					printf("A ");
				
				gotoxy(0, 28);
				Sleep(350);		// 350
			}
		}
		Set_Color(15);
	}

	void Poker_Five_Draw_1_inf()						// ���̺� ��ο� ��Ŀ 1 ����
	{
		int Page = 1;
		int key;
		int Change = 1;
		
		Full_Clear();
		
		gotoxy(30, 22);
		printf("%c%c %c%c�� ������ �ѱ��", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("�����̽� ��, ���� Ű�� �������� ���ư���");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
			
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�� ������ 5���� �ް� Ȯ���� �� �ٲٰ� ���� �� ����ŭ �� ���� �ٲ� ��");
					gotoxy(3,3);
					printf("������ �и� ���� ���� �� ��ŭ�� ���� ��� 1�ο� ���̺� ī�� ��ο� ��Ŀ�Դϴ�.");
					
					gotoxy(3,6);
					printf("���� ���� ����");
					gotoxy(3,8);
					printf("ī�带 �ް� ù ��° ������ �մϴ�.");
					gotoxy(3,9);
					printf("�� �� �ٲ� ī�带 �����մϴ�.");
					gotoxy(3,11);
					printf("���� ī�带 �ް� �����ϱ� ���� �� ��° ������ �մϴ�.");
						 gotoxy(3,12);
					printf("�� �� ��° ������ ������ ��ŭ ���� �ݾ׿��� ������������");
					gotoxy(3,13);
					printf("���� ���� �ݾ׿��� 0.8��� ��޵˴ϴ�.");
					gotoxy(3,15);
					printf("�� ���� ���� �ݾ��� (ù ��° ���� �ݾ� + 0.8 * �� ��° ���� �ݾ�)�Դϴ�.");
					
					
					gotoxy(3,18);
					printf("��Ŀ ���� �� �Ǵ� HP�� 6�� �����մϴ�.");
					
					gotoxy(75,19);
					printf("Page 1/3");
				}
					
				if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�� ������ ������ ���� ������ �����̴� ���� �ʽ��ϴ�.");
					gotoxy(3,3);
					printf("�Ʒ��� �� ������ �����Դϴ�.");
					
					gotoxy(3,5);
					printf("�� ��� : �Ʒ��� ��޵Ǵ� ��� �������� �ش���� �ʴ� ���.");
					gotoxy(3,6);
					printf("          ���� �� ��ŭ ���� �ҽ��ϴ�.");
					gotoxy(3,8);
					printf("�� ��� : ���ڰ� ���� ī�� 2���� ����.");
					gotoxy(3,9);
					printf("          ���� �� �ݾ��� 0.5�踦 �����޽��ϴ�.");
					gotoxy(3,11);
					printf("�� ��� : �� �� 2�� ����.");
					gotoxy(3,12);
					printf("          ���� �� �ݾ��� 0.9�踦 �����޽��ϴ�.");
					gotoxy(3,14);
					printf("Ʈ���� : ���ڰ� ���� ī�� 3���� ����.");
					gotoxy(3,15);
					printf("         ���� �� �ݾ��� 3�踦 ����ϴ�.");
					gotoxy(3,17);
					printf("��Ʈ����Ʈ : ���ڰ� ���ӵ� ī�� 5��.");
					gotoxy(3,18);
					printf("             ���� �� �ݾ��� 20�踦 ����ϴ�.");
					
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("�÷��� : ���� ������� ���̰� ���� ī�� 5��.");
					gotoxy(3,3);
					printf("         ���� �� �ݾ��� 8�踦 ����ϴ�.");
					gotoxy(3,5);
					printf("Ǯ �Ͽ콺 : Ʈ���ð� �� �� ���� ����.");
					gotoxy(3,6);
					printf("           ���� �� �ݾ��� 10�踦 ����ϴ�~");
					gotoxy(3,8);
					printf("��ī�� : ���ڰ� ���� ī�� 4��.");
					gotoxy(3,9);
					printf("         ���� �� �ݾ��� 30�踦 ����ϴ� ~~!!");
					
					gotoxy(75,19);
					printf("Page 3/3");
				}
			}
			
		//	printf("��Ʈ����Ʈ �÷��� : ���ڰ� ���ӵǰ� ���̰� ���� ī�� 5��\n");
		//	printf("�ο� ��Ʈ����Ʈ �÷��� : ���̰� ���� A, K, Q, J, 10\n");
			
			gotoxy(0, 28);
			key = getch();
			if(key == 224)
			{
				key = getch();
				if(key == 75)
				{
					if(1 < Page && Page <= 3)
					{
						Page--;
						Change = 1;
					}
				}
				if(key == 77)
				{
					if(1 <= Page && Page < 3)
					{
						Page++;
						Change = 1;
					}
				}
			}
			
			if(key == 32 || key == 13)
				break;
		}
		ing(0.5);
	}

	
	// �ζ� �Լ�
	void Lottery()									// �ζ�
	{
		int Lottery_re = 1;
		int Lottery[6];
		
		int i;
		
		system("cls");
		
		printf("���ǹ濡 �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Lottery_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Lottery_re == 1)					// �ݺ� ����
		{
			system("cls");
			printf("���� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n\n", HP);
			
			printf("5�� ���忡 10�� ��\n");
			
			printf("���� ?\n");
			while(1)
			{
				printf("Yes 1, No 2 : ");
				scanf("%d", &i);
				if(i == 1 || i == 2)
					break;
			}
			
			if(i == 2)							// �� ��� ����
				break;
			Money -= 10;
			
			printf("\n\n");
			
			for(i = 1; i <= 5; i++)				// ����		
				Lottery[i] = rand()% 1000 + 1;
				
			for(i = 1; i <= 5; i++)				// ��� ���
			{
				if(Lottery[i] <= 450)
				{
					printf("��\n");
				}
				
				else if(Lottery[i] <= 749)
				{
					printf("6��\n");
					Money += 0.5;
				}
				
				else if(Lottery[i] <= 909)
				{
					printf("5��\n");
					Money += 3;
				}
				
				else if(Lottery[i] <= 959)
				{
					printf("4��\n");
					Money += 8;
				}
				
				else if(Lottery[i] <= 989)
				{
					printf("3��~\n");
					Money += 50;
				}
				
				else if(Lottery[i] <= 999)
				{
					printf("2��~~\n");
					Money += 300;
				}
				
				else if(Lottery[i] == 1000)
				{
					printf("1��~~~!!\n");
					Money += 1000;
				}
			}	
			
			if(Money < 10)						// �� ����
			{
				printf("\n�ζ� ���ݺ��� ���� �ݾ��� �����ϴ� �Ф�\n");
				Sleep(2000);
				break;
			}
			
			HP -= 3;
			if(HP <= 0)							// ü��
			{
				HP = 0;
				printf("\nHP�� 0�� �Ǿ����ϴ�...\n");
				Sleep(2000);
				break;
			}
			
			printf("\n���� �� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n\n", HP);
			while(1)							// ��
			{
				printf("\n�ٽ� �Ͻðڽ��ϱ�?\n");
				Lottery_re = YN();
				if(Lottery_re == 1 || Lottery_re == 2)
					break;
			}
		}
		
		printf("\n\n���ǹ��� �����մϴ�");
		ing(3);
	}
	
	void Lottery_inf()							// ����
	{		
		system("cls");
		
		printf("5���� �� ���� ���̸� 10�� ���� �� �� �ֽ��ϴ�.\n");
		
		printf("�Ʒ��� �� ����� �ɸ� Ȯ���� ��÷���Դϴ�.\n\n");
		printf("1�� 0.1 %%  1000�� ��\n");
		printf("2�� 1   %%   300�� ��\n");
		printf("3�� 3   %%    50�� ��\n");
		printf("4�� 5   %%     8�� ��\n");
		printf("5�� 11  %%     3�� ��\n");
		printf("6�� 25  %%   0.5�� ��\n\n");
		printf("��  54.9%%\n\n");
		
		printf("�ζ� �� ���� �ܴµ� HP�� 3 �Ҹ�˴ϴ�.\n\n\n");
		
		printf("�ƹ� ��ư�̳� ���� ���ǹ�����\n");
		getch();
		Sleep(100);
	}

	
	// �� �ŷ��� �Լ�
	int Gold_Store(float Price, int *Have)			// �� �ŷ���
	{
		int Gold_re = 1;
		int trade = 0;
		
		int i;
		
		system("cls");
		
		printf("�� �ŷ��ҿ� �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Gold_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		
		while(Gold_re == 1)
		{
			system("cls");
			printf("���� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n", HP);
			printf("�ݱ� %d�� ������\n\n", *Have);
			printf("���� �ݱ� 1���� ���� ������ %.2lf �� ��\n", Price);
			printf("                �Ǹ� ������ %.2lf �� ���Դϴ�\n\n", Price * 0.8);
			
			while(1)								// ����
			{
				printf("���� 1, �Ǹ� 2, ������ 3 : ");
				scanf("%d", &i);
				
				if(i == 1 || i == 2 || i == 3)
					break;
			}
			
			
			
			switch(i)								// ���� ���� �Ǹ� ������
			{
				case 1:								// ����	
					if(Money < Price)			// ���� ���� ��� ���� �Ұ�
					{
						printf("\n\n���� �ݱ��� ���ݺ��� ���� �ݾ��� ���� ������ �� �����ϴ�.");
						ing(2);
						break;
					}
					while(1)
					{
						i = (Money / Price);
						printf("\n%d������ ���� �����մϴ�.", i);
						printf("�� �� �����Ͻðڽ��ϱ�? (0 �Է½� ���)\n");
						printf("���� : ");
						scanf("%d", &trade);
						
						if(trade == 0)
							break;
						if(trade <= i)
							break;
						
						printf("���� ���ڶ� �׸�ŭ �� �� �����ϴ� !\n");
						ing(2);
					}
					
					Money -= (float)(Price * trade);
					*Have += trade;
					HP -= (trade * 3);
					
					if(trade != 0)
						printf("\n%.2lf �� ������ %d�� �����ϼ̽��ϴ�.\n", Price * trade, trade);
					
					break;
				
				case 2:								// �Ǹ�
					if(*Have == 0)						// ������ �ִ� �� ������ ���ư�
					{
						printf("\n\n�������� �ݱ��� �����ϴ�..");
						ing(2);
						continue;
					}
					
					while(1)
					{
						printf("�� �� �Ǹ��Ͻðڽ��ϱ�? (0 �Է½� ���)\n");
						printf("�Ǹ� : ");
						scanf("%d", &trade);
						
						if(trade <= *Have)
							break;
					}
					
					if(trade == 0)
							break;
						
					Money += (float)(Price * trade);
					*Have -= trade;
					HP -= (trade * 3);
					printf("\n%d���� �Ǹ��� \n%.2lf �� ���� �����̽��ϴ�.\n", trade, Price * trade);
					
					break;
				
				case 3:
					Gold_re = 2;
			}
			
			if(HP <= 0)							// ü��
			{
				HP = 0;
				printf("\nHP�� 0�� �Ǿ����ϴ�...\n");
				Sleep(2000);
				break;
			}	
					
			if(i != 3)
				printf("\n\n�� �ŷ��Ҹ� �����Ͻðڽ��ϱ�?\n");
			
			while(i != 3)							// �� �ŷ��� ��
			{
				i = YN();
						
				if(i == 1)
					Gold_re = 2;
						
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n�� �ŷ��Ҹ� �����մϴ�");
		ing(3);
	}

	int Gold_Change(float *Price, int *Big)		// �ݱ� ���� ����
	{
		int i = 0;
		int P_M;
		
		int one;			// 100�� �ڸ�
		int two;			// 10�� �ڸ�
		int three;			// 1�� �ڸ�
		float four;			// 0.1�� �ڸ�
		float five;			// 0.01�� �ڸ�
		
		float total = 0;
		
		if(*Big == 0)						// ������
			i = rand()% 10 + 1;
		
		if(i == 10)							// ----
			*Big = 3;
		if(i == 3)
			*Big = 10;
			
		
		if(*Big == 0)						// �����ϰ� ����
		{
			i = rand()% 11 + 1;
			
			if(i %2 == 1)
				P_M = 1;
			if(i %2 == 0)
				P_M = -1;
		}
		
		one = rand()% 3;
		two = rand()% 10;
		three = rand()% 10;
		four = rand()% 10;
		five = rand()% 10;
		
		
		if(*Big != 0)					// ������
		{
			if(*Big <= 3)				// ----
			{
				one = 2;
				P_M = -1;
				*Big -= 1;
			}
			
			if(*Big == 10)				// ++++
			{
				one = 5;
				P_M = 1;
			}
			
		}
		
		total += (float)(P_M)*((one * 100) + (two * 10) + (three * 1) + (four * 0.1) + (five * 0.01));
		
		*Price += total;
		if(*Price < 500)
			*Price = 500;
	}
	
	void Gold_inf()								// ����
	{
		system("cls");
		
		printf("ó�� �ݱ� �� ���� ������ 1000�� ��������\n");
		printf("���� ���� ������ �����ϰ� �ݱ��� ������ �����մϴ�.\n");
		printf("�ݱ��� ������ 500�� �� �Ʒ��δ� �������� �ʽ��ϴ�.\n");
		printf("���� ������ -299.99 ~ +299.99 �� �������� ���õ˴ϴ�.\n\n");
		printf("���� Ȯ���� �ݱ� ������ �̺�Ʈ�� �߻��մϴ�.\n");
		printf("�߻��� ��� 3�� ���� �ݱ��� ������ 3~400�� ���� �������ϴ�.\n");
		printf("���ڱ� ������ �ٴ� ��쵵 �ֽ��ϴ�.\n");
		printf("�ݱ��� ������ �� �ŷ��ҿ����� Ȯ���� �� �ֽ��ϴ�.\n");
		printf("�� ���� ������ ������ 0.8��� �Ľ� �� �ֽ��ϴ�\n\n");
		
		printf("�� ���� �ݱ��� ����� ������ HP�� 3�� �����մϴ�.\n\n\n");
		
		printf("�ƹ� ��ư�̳� ���� �� �ŷ��ҷ�\n");
		getch();
		Sleep(100);
	}
		
		
	// �渶�� �Լ�
	void Race()										// �渶��
	{
		int i;
		
		int Race_re = 1;
		int Race_Count = 1;				// �渶 ī����
		
		int Horse_Select;
		int Horse_Win = 0;
		int WW = 0;
		
		int bet;
		
		system("cls");
		
		printf("�渶�忡 �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Race_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Race_re == 1)
		{
			WW = 0;
			
			system("cls");
			
			printf("���� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n\n", HP);
			printf("%d�� ° �����Դϴ�.\n", Race_Count);
			printf("�� �� ���� �����Ͻðڽ��ϱ�?\n");					// �� ����
			while(1)
			{
				printf("(0 �Է½� ���) : ");
				scanf("%d", &Horse_Select);
								
				if(0 <= Horse_Select && Horse_Select <= 3)
					break;
			}
			if(Horse_Select == 0)
				break;
			
			printf("\n%d�� ���� �󸶳� �����Ͻðڽ��ϱ�?\n", Horse_Select);					// ����
			while(1)
			{
				printf("(0�Է½� ���) : ");
				scanf("%d", &bet);
								
				if(0 <= bet && bet <= Money)
					break;
			}
			Money -= bet;
			if(bet == 0)
				break;
			
			Horse_Win = Race_Start(Horse_Select);
			printf("\n\n");
			if(Horse_Win <= 3)
				printf("%d�� ���� 1���Դϴ�.", Horse_Win);
			if(Horse_Win == 12)
				printf("1�� ���� 2�� ���� ���� 1���Դϴ�.");
			if(Horse_Win == 13)
				printf("1�� ���� 3�� ���� ���� 1���Դϴ�.");
			if(Horse_Win == 23)
				printf("2�� ���� 3�� ���� ���� 1���Դϴ�.");
			
			
			printf("\n\n\n");
			
			if(Horse_Select == 1 && Horse_Win == 12)		// ���� 1��
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 3);
				Money += (float)(bet * 3);
				WW = 1;
			}
			
			if(Horse_Select == 1 && Horse_Win == 13)
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 3);
				Money += (float)(bet * 3);
				WW = 1;
			}
			
			if(Horse_Select == 2 && Horse_Win == 12)
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 2);
				Money += (float)(bet * 2);
				WW = 1;
			}
			
			if(Horse_Select == 2 && Horse_Win == 23)
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 2);
				Money += (float)(bet * 2);
				WW = 1;
			}
			
			if(Horse_Select == 3 && Horse_Win == 13)
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 1.5);
				Money += (float)(bet * 1.5);
				WW = 1;
			}
			
			if(Horse_Select == 3 && Horse_Win == 23)
			{
				printf("1�� ���� ���߼̽��ϴ� !!\n");
				printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 1.5);
				Money += (float)(bet * 1.5);
				WW = 1;
			}
			
			if(Horse_Select == Horse_Win)
			{
				WW = 1;
				if(Horse_Select == 1)						// 1�� ��	
				{
					printf("1�� ���� ���߼̽��ϴ� !!\n");
					printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 3);
					Money += (float)(bet * 3);
				}
				
				if(Horse_Select == 2)						// 2�� ��
				{
					printf("1�� ���� ���߼̽��ϴ� !!\n");
					printf("%d �� ���� ȹ���߽��ϴ� !\n\n", bet * 2);
					Money += (float)(bet * 2);
				}
				
				if(Horse_Select == 3)						// 3�� ��
				{
					printf("1�� ���� ���߼̽��ϴ� !!\n");
					printf("%.2lf �� ���� ȹ���߽��ϴ� !\n\n", bet * 1.5);
					Money += (float)(bet * 1.5);
				}
			}
			if(WW == 0)
			{
				printf("1�� ���� ������ ���Ͽ����ϴ�..\n\n");			// �й�
			}
			
			HP -= 5;
			
			if(Money == 0)									// 0��
			{
				printf("�渶�忡�� ���� ���� �����̽��ϴ� �Ф�\n");
				Sleep(2000);
				break;
			}
			else if(Money < 1)
			{
				printf("���� �ּ� �ݾ׺��� ���� �ݾ��� ���ڶ��ϴ�....\n");
				Sleep(2000);
				break;
			}
			
			printf("���� �� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n", HP);
			while(1)							// ��
			{
				printf("\n�ٽ� �Ͻðڽ��ϱ�?\n");
				Race_re = YN();
				if(Race_re == 1 || Race_re == 2)
					break;
			}
			
			Race_Count++;
		}
		printf("\n\n�渶���� �����մϴ�");
		ing(3);
	}
	
	void Race_inf()								// ����
	{
		system("cls");
		
		printf("�� ������ �� �߿� � ���� ���� ���� ������ ���ߴ� �����Դϴ�.\n");
		printf("Ʈ���� �� 30ĭ���� �̷���� ������ 2�ʸ��� 0~5ĭ�� �������� �����Դϴ�.\n");
		printf("�� �� ������ ������ ���� 1�� ������ �����ϴ�.\n");
		printf("���ÿ� ���� ��� ���� 1���� Ĩ�ϴ�.\n\n");
		
		printf("���� ���� �ϴ� �ִ� �ӵ��� ���� �ٸ��ϴ�.\n");
		printf("1�� ���� 0~4ĭ\n");
		printf("2�� ���� 0~5ĭ\n");
		printf("3�� ���� 0~6ĭ\n");
		printf("1�� ���� ���� ��� ���� ���� �ݾ��� 3��, 2��, 1.5�踦 ȹ���մϴ�.\n\n");
		
		printf("�渶 �� ���Ӵ� HP�� 5�� �����մϴ�.\n\n");
		
		printf("�ƹ� ��ư�̳� ���� �渶������\n");
		getch();
		Sleep(100);
	}

	int Race_Start(int Select)					// �渶 ����
	{
		int i;
		int j;
		int Win = 0;
		
	//	int HM;
		int Horse[4] = {0, 0, 0, 0};
		
			
		while(Win == 0)
		{
			int Fast[4] = {0, 0, 0, 0};
			
			system("cls");								// ���� �ʱ�ȭ
						
			printf("S----------------------------F\n");	// 30ĭ
			
			for(i = 1; i <= 3; i++)
			{
				if(i == 1)												// 1�� ����
				{
					Fast[1] = rand()%5;									// 0ĭ ~ 4ĭ
					Horse[1] += Fast[1];
					if(Fast[1] != 0 && Fast[1] != 4)
						Fast[1] = 1;
				}
				if(i == 2)												// 2�� ����
				{
					Fast[2] = rand()%6;									// 0ĭ ~ 5ĭ
					Horse[2] += Fast[2];
					if(Fast[2] != 0 && Fast[2] != 5)
						Fast[2] = 1;
				}
				if(i == 3)												// 3�� ����
				{
					Fast[3] = rand()%7;									// 0ĭ ~ 6ĭ
					Horse[3] += Fast[3];
					if(Fast[3] != 0 && Fast[3] != 6)
						Fast[3] = 1;
				}
		
				for(j = 1; j <= Horse[i]; j++)							// ĭ �̵�
					printf(" ");
				
				if(Horse[i] >= 30)										// ��� ���� �� ����
				{
					for(j = 30; j <= Horse[i]; j++)
						printf("\b");
				}
				
				printf("%d", i);
				
				if(Horse[i] >= 29)										// ��� �� ���
					printf("��\n");
				else
					printf("\n");
					
			}
			printf("S----------------------------F\n\n");	// 30ĭ	
			
			if(Horse[1] >= 29 || Horse[2] >= 29 || Horse[3] >= 29)		// �¸� ����
			{
				if(Horse[1] > Horse[2] && Horse[1] > Horse[3])		// 1�� �� �¸�
					Win = 1;
				
				if(Horse[2] > Horse[1] && Horse[2] > Horse[3])		// 2�� �� �¸�
					Win = 2;
					
				if(Horse[3] > Horse[1] && Horse[3] > Horse[2])		// 3�� �� �¸�
					Win = 3;
				
				if(Win == 0)
				{
					if(Horse[1] == Horse[2])							// 1&2 ����
						Win = 12;
						
					if(Horse[1] == Horse[3])							// 1&3 ����
						Win = 13;
						
					if(Horse[2] == Horse[3])							// 2&3 ����
						Win = 23;
				}
			}
			
			for(i = 1; i <= 3; i++)
			{
				if(Win == 0 && Fast[i] > 3)
					printf("%d�� ���� ������ �����մϴ� !!\n", i);
				if(Win == 0 && Fast[i] == 0)
					printf("%d�� ���� ���ϴ�....\n", i);
			
			}
			Sleep(850);										// ���帶�� Ȯ��
		}
		
		return Win;
	}
	
	
	
// �ü�
	// ȣ�� �Լ�
	void Hotel()
	{	
		int Hotel_Count	= 0;		// ȣ�� ��¥ ī����
		int i;
		
		system("cls");
		printf("ȣ�ڿ� �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("���� ���� %.2lf �� �� \n", Money);
		printf("HP : %d\n", HP);
		printf("\nȣ�ڿ��� �޽��� ���Ͻðڽ��ϱ�?\n");
		printf("�Ϸ� ���� HP+100, �� - 100 ��\n");				
		while(1)
		{
			i = YN();
			
			if(i == 1)
			{
				printf("\n\n�޽���");
				ing(3);
				
				HP += 100;
				if(HP > (100 + (Drink * 30)))
					HP = 100 + (Drink * 30);
				
				Money -= 100;
				
				system("cls");
			}	
			
			if(i == 2)
				break;
			
			if(Money < 100)
			{
				printf("���� ��� ȣ�ڿ� �� �ӹ��� �� �����ϴ�.\n");
				break;
			}
			printf("�Ϸ� �� ���ðڽ��ϱ�?\n");
			Hotel_Count++;
		}
		
		if(Hotel_Count != 0)
			Day += (Hotel_Count-1);
		
		printf("\nȣ�ڿ��� �����մϴ�");
		ing(3);
		
	}
	
	
	// ���۰��� �Լ�
	void Hole()
	{
		int i;
		int Many;
		
		int Hole_re = 1;
		
		system("cls");
		printf("���۰��Կ� �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("��ǰ�� ������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Hole_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Hole_re == 1)
		{
			system("cls");
			
			printf("���� ���� %.2lf �� �� \n", Money);
			printf("HP : %d\n", HP);
			
			printf("\n��ǰ �̸�   | ����\n\n");
			printf("1. ��ȭ��    1000 �� ��\n");
			printf("2. ȣ����   200 �� ��\n");
			
			printf("\n\n\n");
			printf("������ ����? (0 �Է½� ���) : ");
			
			while(1)
			{
				scanf("%d", &i);
				if(0 <= i && i <= 2)
					break;
			}
			
			switch(i)
			{
				case 0:
					break;
					
				case 1:
					i = (Money / 1000);
					
					if(Money < 1000)
					{
						printf("���� �ݾ��� ���ڶ� �����Ͻ� �� �����ϴ�!.");
						ing(1);
						break;
					}
					
					Many = Hole_Purchase(&Many, i);
					if(Many == 0)
						break;
					
					printf("\n\n%d �� ������ %d�� �����ϼ̽��ϴ�.", (Many * 1000), Many);
					Money -= (Many * 1000);
					Drink += Many;
					break;
					
				case 2:
					i = (Money / 200);
					
					if(Money < 200)
					{
						printf("���� �ݾ��� ���ڶ� �����Ͻ� �� �����ϴ�!.");
						ing(1);
						break;
					}
					
					Many = Hole_Purchase(&Many, i);
					if(Many == 0)
						break;
					
					printf("\n\n%d �� ������ %d�� �����ϼ̽��ϴ�.", (Many * 200), Many);
					Money -= (Many * 200);
					Whistle += Many;
					break;
			}
			printf("\n\n���۰��Ը� �����Ͻðڽ��ϱ�?\n");
			while(1)							// ���۰��� ��
			{
				i = YN();
						
				if(i == 1)
					Hole_re = 2;
				
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n���۰��Ը� �����մϴ�");
		ing(3);
	}
	
	void Hole_inf()
	{
		system("cls");
		printf("\n\n\n");
		
		printf("1. ��ȭ��   : �ִ� HP�� 30 �÷��ݴϴ�.\n");
		printf("2. ȣ���� : 80%% Ȯ���� ���и� ���ѽ��ϴ�.\n");
		
	//	printf("3. \n");
		
		printf("\n\n\n");
		printf("�ƹ� ��ư�̳� ���� ���� ���Է�\n");
		getch();
		Sleep(100);
	}
	
	int Hole_Purchase(int *M, int Can)
	{
		printf("\n%d������ ���� ���� : ", Can);
		while(1)
		{
			scanf("%d", &*M);
			if(0 <= *M && *M <= Can)
			break;
		}
		return *M;
	}
	
	
	// ���� �Լ�
	void Bank()
	{
		int i;
		int Choice;
		int Bank_re = 1;
		int s;
		
		
		
		system("cls");
		
		printf("���࿡ �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Bank_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Bank_re == 1)										// ���� �ݺ�
		{
			int Bank_Storage = 0;
			
			for(i = 1; i <= 9; i++)
			{
				if(Saving[i] == 1)
					Bank_Storage += Ten_Square(i);
			}
			system("cls");
			
			printf("���� ���� %.2lf �� ��\n", Money);
			printf("������ �ݾ� %d �� ��\n\n", Bank_Storage);
			
			printf("������ �Ͻðڽ��ϱ� ?\n");
			while(1)
			{
				printf("1. ����, 2. ���, 3. ������ : ");		// ����
				scanf("%d", &Choice);
				if(0 <= Choice && Choice <= 3)
					break;
			}
			
			printf("\n\n");
			
			switch(Choice)
			{
				case 1:														// ����
					for(s = 1; s <= 9; s++)
					{
						if(Saving[s] == 0)
							printf("%10d �� �� ���� ����\n", Ten_Square(s));
					}
					printf("\n\n");
					while(1)
					{
						printf("�󸶸� �����Ͻðڽ��ϱ�?\n");
						printf("(0 �Է½� ���) : ");
						scanf("%d", &s);
						
						if(s == 0)
							break;
						
						if(s > Money)					// ���� ���ڶ� ��
						{
							printf("�Է��� �ݾ׺��� ���� �ݾ��� ���� ������ �� �����ϴ�.\n\n");
							continue;
						}
						
						if(Saving[Ten_Divide(s)] == 0)
						{
							printf("\n%d �� �� �����ϼ̽��ϴ�.\n", s);
							Money -= s;
							Saving[Ten_Divide(s)] = 1;
							Sleep(1000);
							break;
						}
						else
							printf("%d �� ���� �̹� ������ ���� �ֽ��ϴ�.\n\n", s);
					}
					break;
					
				case 2:												// ���
					for(s = 1; s <= 9; s++)
					{
						if(Saving[s] == 1)
							printf("%10d �� �� ��� ����\n", Ten_Square(s));
					}
					printf("\n\n");
					printf("�󸶸� ����Ͻðڽ��ϱ�?\n");
					while(1)
					{
						printf("(0 �Է½� ���) : ");
						scanf("%d", &s);
						
						if(s == 0)
							break;
						
						if(Saving[Ten_Divide(s)] == 1)
						{
							printf("%d �� �� ����ϼ̽��ϴ�.\n", s);
							Money += s;
							Saving[Ten_Divide(s)] = 0;
							Sleep(1000);
							break;
						}
						else
							printf("%d �� ���� ������ ���� �����ϴ�.\n", s);
					}
					break;
						
				case 3:												// ������
					Bank_re = 2;
			}
		}
		
		printf("\n\n������ �����մϴ�");
		ing(3);
	}
	
	void Bank_inf()
	{
		system("cls");
		
		printf("������ ���� �����ϰ� �Ϸ翡 10%�� ���ڸ� ���� �� �ֽ��ϴ�.\n");
		printf("���ڴ� ���࿡�� �Ҿ�� �ʰ� �ƴ� ���� �ݾ׿� ���� �߰��˴ϴ�.\n");
		printf("������ 10 ��, 100 ��, 1000 �� ���� 10�� �������θ� �����մϴ�.\n");
		printf("�� �ݾ״� �ѹ��ۿ� ������ �� �����ϴ�.\n");
		printf("ex)1111 �� �� ���� ����, 1112 �� �� ���� �Ұ�, 3201 �� �� ���� �Ұ�\n\n\n");
		
		printf("�ƹ� ��ư�̳� ���� ��������\n");
		getch();
		Sleep(100);
	}
	

	// �ε���
	void Real_Estate()
	{
		int i;
		int Real_Estate_re = 1;
		
		system("cls");
		
		printf("�ε��꿡 �����߽��ϴ�\n\n");
		Sleep(500);
		
		printf("������ ���ðڽ��ϱ�?\n");
		while(1)								// ����
		{
			i = YN();
			
			if(i == 1)
				Real_Estate_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Real_Estate_re == 1)
		{
			system("cls");
			printf("���� ���� %.2lf �� ��\n\n", Money);
			switch(House_Have)
			{
				case 0:								// �� ����
					printf("���� �����Ͻðڽ��ϱ�?\n");
					printf("���� 2000 �� ��\n");
					while(1)						// ����
					{
						i = YN();
						
						if(i == 1 || i == 2)
							break;
					}
					
					if(i == 1)
					{
						if(Money < 2000)
						{
							printf("���� ���ڶ� ���� ������ �� �����ϴ�.\n");
							ing(1);
						}
						if(Money >= 2000)
						{
							printf("\n\n2000 �� ������ ���� �����Ͽ����ϴ�.\n");
							ing(1);
							House_Have = 1;
							Money -= 2000;
						}
					}
					break;
					
				case 1:
					printf("���� �Ǹ��Ͻðڽ��ϱ�?\n");
					printf("���� 2000 �� ��\n");
					while(1)						// �Ǹ�
					{
						i = YN();
						
						if(i == 1 || i == 2)
							break;
					}
					if(i == 1)
					{
						printf("���� �Ǹ��� 2000 �� ���� ȹ���߽��ϴ�.\n");
						ing(1);
						House_Have = 0;
						Money += 2000;
					}
					break;
			}
			
			
			printf("\n\n�ε����� �����Ͻðڽ��ϱ�?\n");
			while(1)							// �ε��� ��
			{
				i = YN();
						
				if(i == 1)
					Real_Estate_re = 2;
				
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n�ε����� �����մϴ�");
		ing(3);
	}
	
	void Real_Estate_inf()
	{
		system("cls");
		
		printf("�ε��꿡���� �ڽŸ��� ���� ������ �� �ֽ��ϴ�.\n");
		printf("���� �� �����ۿ� �����ϴ�.\n");
		printf("���� ���� �� ���� �� ���� �ֽ��ϴ�.\n\n");
		
		printf("���� HP�� �ִ�� ȸ�������ݴϴ�.\n\n");
		
		printf("�ƹ� ��ư�̳� ���� �ε�������\n");
		getch();
		Sleep(100);
	}
	
	
// ��Ÿ
	// ������ Ȯ��
	void Item_Check()
	{
		system("cls");
		
		printf("1. ��ȭ��   %d�� ������\n", Drink);
		printf("2. ȣ���� %d�� ������\n", Whistle);
	//	printf("3. 
		
		printf("\n\n\n");
		printf("�ƹ� ��ư�̳� ���� �޴���\n");
		getch();
		Sleep(100);
	}
	
	
	// ��
	void House()
	{
		int House_Count = 0;
		int i;
		
		system("cls");
		
		printf("���� ���Խ��ϴ�\n\n");
		Sleep(500);
		
		printf("���� ���� %.2lf �� �� \n", Money);
		printf("HP : %d\n", HP);
		printf("�ִ� HP : %d\n", (100 + 30 * Drink));
		printf("\n������ �޽��� ���Ͻðڽ��ϱ�?\n");
		printf("�Ϸ� ���� HP �ִ� ȸ��\n");				
		while(1)
		{
			i = YN();
			
			if(i == 1)
			{
				printf("\n\n�޽���");
				ing(3);
				
				HP = (100 + 30 * Drink);
				
				system("cls");
			}	
			
			if(i == 2)
				break;
			
			printf("�Ϸ� �� ���ðڽ��ϱ�?\n");
			House_Count++;
		}
		
		if(House_Count != 0)
			Day += (House_Count-1);
		
		printf("\n������ �����ϴ�");
		ing(3);
		
	}
	
	
	
	
	
	