	#include <stdio.h>	// gotoxy(0, 28);
	#include <stdlib.h>
	#include <windows.h>
	#include <time.h>
	#include <conio.h>
	#include <math.h>
	
	float Money = 500.12;									// 화폐 (만)
	int HP = 100;										// 체력 게이지
	int Gold_Have = 0;									// 금괴 보유
	int Saving[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	// 저금
	int House_Have = 0;									// 집 보유
	
	
	int Day = 1;										// 날짜 카운팅

	// 아이템
	int Drink = 0;			// 최대 체력 증가
	int Whistle = 0;		// 호루라기
	

// 화면 그리기
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
	
	
// 초기 메뉴
	void First_Menu();
	void First_inf();
		
// 공통
	int YN();
	void ing(float n);
	void gotoxy(int x, int y);
	int Ten_Square(int num);
	int Ten_Divide(int num);
	
	
// 게임
	// 포커
	void Poker_Room();
	void Poker_Room_inf();
	void Show(int x, int y, int N, int T, int i);
	void Poker_Five_Draw_1();
	void Poker_Five_Draw_1_inf();
	void ShowCard(int N[], int T[], int C[]);
	
	// 로또
	void Lottery();						
	void Lottery_inf();
	
	// 금 거래소
	int Gold_Store(float Price, int *Have);
	void Gold_inf();
	int Gold_Change(float *Price, int *Big);
	
	// 경마장
	void Race();
	void Race_inf();
	int Race_Start(int Select);
	
// 시설
	// 호텔
	void Hotel();
	
	// 구멍가게
	void Hole();
	void Hole_inf();
	int Hole_Purchase(int *M, int Can);
	
	//은행
	void Bank();
	void Bank_inf();
	
	// 부동산
	void Real_Estate();
	void Real_Estate_inf();
	
// 기타
	// 아이템 확인
	void Item_Check();
	
	// 집
	void House();
	
	
//////////////////////////////////////////////////////////////////////////////// 코드 시작

// 그리기
	void Edge()
	{
		int i;
		
		for(i = 0; i <= 42; i++)			// 메인 가로
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
			
		for(i = 0; i<= 28; i++)				// 메인 세로
		{
			gotoxy(0, i);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(84, i);
			printf("%c%c", 0xa2, 0xcc);
		}
		
		for(i = 0; i < 10; i++)			// 선택 가로
		{
			gotoxy(88 + i * 2, 20);
			printf("%c%c", 0xa2, 0xcc);
			
			gotoxy(88 + i * 2, 26);
			printf("%c%c", 0xa2, 0xcc);
		}
		
		for(i = 0; i < 6; i++)				// 선택 세로
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
		printf("방향키와 스페이스바(엔터)로 조작 !");
	}

	void Status()
	{
		gotoxy(88, 1);printf("%d일 째\n", Day);
		
		gotoxy(88, 3);printf("                         ");
		gotoxy(88, 3);printf("현재 보유 %.2lf 만 원", Money);
		
		gotoxy(88, 4);printf("HP : %d     ", HP);
		
		gotoxy(88, 5);printf("금괴 %d개 보유중", Gold_Have);
	}
	
	void Map_1_Draw()
	{
		int i = 0xa1;
		int j = 0xac;
		
//윗 줄	
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
		printf(" |    포커방     |   |   복권방      |       |   금 거래소   |  |     경마장    |");
		gotoxy(2, 7);
		printf(" |               |   |               |       |               |  |               |");
		gotoxy(2, 8);
		i = 0xa2, j = 0xc6;
		printf(" |______%c%c_______|   |______%c%c_______|       |______%c%c_______|  |_______%c%c______|", i, j, i, j, i, j, i, j);
		gotoxy(2, 9);
		i = 0xa1, j = 0xd9;
		printf("        %c%c                  %c%c                      %c%c                  %c%c", i, j, i, j, i, j, i, j);
		
//아랫 줄
		gotoxy(2, 12);
		printf("  ______%c%c_______     ______%c%c_______         ______%c%c_______    _______%c%c______", i, j, i, j, i, j, i, j);
		gotoxy(2, 13);
		i = 0xa2, j = 0xc6;
		printf(" |      %c%c       |   |      %c%c       |       |      %c%c       |  |       %c%c      |", i, j, i, j, i, j, i, j);
		gotoxy(2, 14);
		printf(" |               |   |               |       |               |  |               |");
		gotoxy(2, 15);
		printf(" |      호텔     |   |        집     |       |     부동산    |  |   장기 팔기   |");
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
	
	
	
// 메인
	int main()							// 메인 함수
	{
		int M_S;
		int Map = 1;
		int Map_1[21][43] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 벽
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1},
		{1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
		{1,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,0,0,0,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1},
		{1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 벽
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
		
		Set_Color(15);				// 글씨 색 흰색

		system("mode con cols=115 lines=30");	// 화면 크기 조절
	
		system("cls");
		Edge();
		
		First_Menu();					// 메인 메뉴에서 게임 설명 선택 가능
		
		
		while(1)
		{	
			Day_f = 1;
			
			Full_Clear();
			
			if(0 < Gold_B && Gold_B < 3)				// 금괴 대폭락
			{
				gotoxy(3, 24);
				printf("금괴의 값이 폭락하는 중입니다!!\n\n");
			}
			if(Gold_B == 10)
			{
				gotoxy(3, 24);
				printf("금괴의 값이 갑자기 뛰었습니다!!!\n\n");
				Gold_B = 0;
			}
			
			if(Map == 1)				// 맵 1일 때 화면 그리기
			{
				i = 0xa1, j = 0xd9;
				gotoxy(40, 0);			// 별
				printf("%c%c%c%c%c%c", i, j, i, j, i, j);
				gotoxy(40, 20);
				printf("      ", i, j, i, j, i, j);
				Map_1_Draw();
			}
			
			M_S = 0;					// 메뉴 초기화
			
			gotoxy(x, y);
			printf("%c%c", 0xa1, 0xdc);
			
			while(M_S == 0)				// 메뉴 인식
			{
				Status();
				
				gotoxy(0, 28);
				Move = getch();
				
				if(Move == 27)				// ESC 입력시 종료
					exit(0);
				
				if(Move == 224)				// 방향키 인식
				{
					Move = getch();
					gotoxy(x, y);			// 지우기
					printf("  ");
					
					switch(Move)
					{
						case 72:			// 위
							if(Map == 1)
							{
								if(Map_1[y-1][x/2] != 1)
									y -= 1;
							}
							break;
						
						case 75:			// 왼쪽
							if(Map == 1)
							{
								if(Map_1[y][(x/2)-1] != 1)
									x -= 2;
							}
							break;
						
						case 77:			// 오른쪽
							if(Map == 1)
							{
								if(Map_1[y][(x/2)+1] != 1)
									x += 2;
							}
							break;
						
						case 80:			// 아래
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
				
				if(20 <= x/2 && x/2 <= 22 && y == 0)				// 위 쪽 통로
				{
					if(Map == 1)
					{
						gotoxy(3, 22);
						printf("마을을 나가 게임을 종료하시겠습니까?");
						
						i = YN();
						
						if(i == 1)
							exit(0);
						
						if(i == 2)
						{
							Long_Clear();
							y += 2;
							
							i = 0xa1, j = 0xd9;
								
							gotoxy(40, 0);			// 별
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
					case 1:														// 포커방
						if(Money < 1)
						{
							printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
							ing(1);
							break;
						}
						
						printf("포커방에 입장합니다.");
						ing(1);
						Poker_Room();
						
						y += 1;
						break;
						
					case 2:
						if(Money < 10)
						{
							printf("로또 가격보다 보유 금액이 적어 입장할 수 없습니다.");	// 복권방
							ing(1);
							break;
						}
						printf("복권방에 입장합니다.");
						ing(1);
						Lottery();
						
						y += 1;
						break;
						
					case 3:
						printf("금 거래소에 입장합니다.");
						ing(1);
						Gold_Store(Gold_Price, &Gold_Have);
						
						y += 1;
						break;
						
					case 4:
						if(Money < 1)
							{
								printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
								ing(1);
								break;
							}
						printf("경마장에 입장합니다.");
						ing(1);
						Race();
						
						y += 1;
						break;
						
					case 5:														// 호텔
						if(Money < 100)
						{
							printf("호텔 비용보다 보유 금액이 적어 입장할 수 없습니다.");
							ing(1);
							break;
						}
						printf("호텔에 입장합니다.");
						ing(1);
						Hotel();
						
						y -= 1;
						break;
							
					case 6:
						if(House_Have == 0)
						{
							printf("집을 아직 구매하지 않았습니다.");
							Day_f = 2;
							ing(1);
						}
						
						if(House_Have == 1)
						{
							printf("집에 입장합니다.");
							ing(1);
							House();
						}
						
						y -= 1;
						break;
					case 7:
						printf("부동산에 입장합니다.");
						ing(1);
						Real_Estate();
						
						y -= 1;
						break;
						
					case 8:														// 장기
						if(Money < 100)
						{
							HP += 50;
							if(HP > (100 + (Drink * 30)))
								HP = 100 + (Drink * 30);
							Money += 100;
							printf("의사가 신장을 때면서 HP를 회복시켜주었습니다\n");
							printf("불법으로 신장을 팔아 100만 원을 얻었습니다.");
						}
						else 
						{
							printf("돈이 없을 때만 찾아갑시다.");
							Day_f = 2;
						}
						ing(1);
						
						y -= 1;
						break;
						
					case 9:
						printf("구멍가게에 입장합니다.");
						ing(1);
						Hole();
						
						break;
						
					case 10:
						printf("보유 아이템을 확인중입니다.");
						ing(1);
						Item_Check();
						Day_f = 2;
						break;
						
					case 11:
						printf("은행에 입장합니다.");
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
						
					case 99:														// 게임 종료
						printf("게임을 종료합니다.");
						ing(1);
						exit(0);
					
					default:
						Day_f = 2;
				}
			}

			/*			printf("1. 포커방\n");
			printf("2. 즉석 복권\n");
			printf("3. 금 거래소\n");
			printf("4. 경마장\n");
			printf("5. 호텔\n");
			printf("6. 집\n");
			printf("7. 부동산\n");
			printf("8. 장기 팔기\n");
			printf("9. 구멍가게\n");
			printf("10. 보유 아이템 확인\n");
			printf("11. 은행\n");
//Test		printf("55. 테스트 HP 깎기\n");
//Test		printf("66. 테스트 돈 증가\n");
//Test		printf("77. 테스트 날짜 지남\n");
			printf("99. 마을 나가기\n");
			
			gotoxy(0, 22);
			printf("\nChoice : ");
			scanf("%d", &M_S); */
			
			printf("\n\n");
			
			
			if(HP == 0 && Whistle != 0)						// 호루라기 사용
			{
				system("cls");
				
				printf("HP가 0입니다..\n");
				printf("비틀거리면서 걸어가다가 깡패를 만났습니다.");
				ing(2);
				printf("\n\n\n호루라기를 불러 도움을 청합니다.");
				ing(3);
				i = rand() % 5 + 1;

				if(i <= 4)
				{
					printf("\n\n'이봐 거기 뭐야!'\n");
					printf("사람들이 와주었습니다.\n");
					printf("깡패가 호다닥 도망갑니다.\n");
					ing(3);
				}
				else
				{
					printf("\n\n아무도 오지 않았습니다...\n");
					printf("깡패에게 돈을 빼앗겼습니다\n");
					
					
					if(Money > 200)
					{
						i = (Money / 2);
						printf("- %d만 원....\n", i);
						Money -= i;
					}
					else if(Money >= 100)
					{
						printf("- 100만 원....\n");
						Money -= 100;
					}
					else
					{
						printf("- %.2lf만 원....\n");
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
				printf("HP가 0입니다..\n");
				Sleep(1500);
				printf("비틀거리면서 걸어가다가 깡패한테 돈을 빼앗겼습니다..\n");
				Sleep(1500);
				
				if(Money > 200)
				{
					i = (Money / 2);
					printf("- %d만 원....\n", i);
					Money -= i;
				}
				else if(Money >= 100)
				{
					printf("- 100만 원....\n");
					Money -= 100;
				}
				else
				{
					printf("- %.2lf만 원....\n");
					Money = 0;
				}
				
				ing(2);
				HP = 10;
			}
				
			int Bank_Storage_Main = 0;						// 저금한 금액
			for(i = 1; i <= 9; i++)
			{
				if(Saving[i] == 1)
					Bank_Storage_Main += Ten_Square(i);
			}
				
				
			if(Day_f == 1)												// 건물에 들어갔다가 나오면 하루 지남
			{
				Day++;													
				Gold_Change(&Gold_Price, &Gold_B);					// 금값 변동
				Money += (Bank_Storage_Main / 10);						// 이자 추가
			}
		}
		
		return 0;
	}

	
// 초기 메뉴	
	void First_Menu()					// 메뉴
	{
		int i = 1;					// 메뉴 선택
		int key= 0;					// 키 인식
		
		while(1)
		{
			system("cls");
			Edge();
			Title();
			
			gotoxy(38, 14);
			printf("시작 %c%c", 0xa1, 0xdb);
			gotoxy(38, 15);
			printf("설명 %c%c", 0xa1, 0xdb);
			gotoxy(38, 16);
			printf("종료 %c%c", 0xa1, 0xdb);
			
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
	
	void First_inf()					// 초기 설명
	{
		int Page = 1;
		int key;
		int Change = 1;
		
		system("cls");
		Edge();
		
		gotoxy(30, 22);
		printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("스페이스 바, 엔터 키로 게임으로 돌아가기");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
				
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("겜블 타운은 도박 마을을 방문하는 게임입니다.");
					gotoxy(3,3);
					printf("여러 가지 게임과 편의 시설들을 선택할 수 있습니다.");
					
					int i = 0xa1;
					gotoxy(3,5);
					printf("%c%c %c%c %c%c %c%c 방향키를 이용해 맵을 돌아다닐 수 있으며", i,0xe8, i,0xe9, i,0xe7, i,0xe6);
					gotoxy(3,6);
					printf("스페이스바 나 엔터를 눌러 메뉴를 열 수 있습니다.");
					gotoxy(3,7);
					printf("벽과 건물을 뚫고 다닐 수 없으며");
					gotoxy(3,8);
					printf("건물 앞의 문으로 가면 건물로 입장할 수 있습니다.");
					
					gotoxy(3,10);
					printf("첫 번째 맵의 위로 가면 마을을 나갈 수 있으며");
					gotoxy(3,11);
					printf("             아래로 가면 두 번째 맵으로 이동합니다.");
					gotoxy(3,13);
					printf("두 번째 맵에서 위로 가면 첫 번째 맵으로 이동하며");
					gotoxy(3,14);
					printf("               아래로 가면 세 번째 맵으로 이동하는 식으로 이루어져 있습니다.");
					
					gotoxy(3,18);
					printf("게임들의 기본적인 설명은 건물 안에 들어가 확인할 수 있습니다.");
					
					gotoxy(75,19);
					printf("Page 1/3");
				}
					
				if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("건물을 들어갔다가 나올 때마다 하루가 흘러갑니다.");
					gotoxy(3,3);
					printf("주식과 금괴의 가격은 하루마다 변동합니다.");
					
					gotoxy(3,5);
					printf("은행은 하루에 10%%의 이자가 생깁니다.");
					
					gotoxy(3,7);
					printf("여러 가지 행동을 할 때마다 HP가 감소하는데");
					gotoxy(3,8);
					printf("HP가 0이 되면 깡패에게 돈을 빼앗깁니다.");
					gotoxy(3,9);
					printf("빼앗기는 돈은 기본적으로 100만 원이며");
					gotoxy(3,10);
					printf("보유 금액이 200만 원을 넘어갈 경우 절반을 빼앗깁니다.");
					
					gotoxy(3,12);
					printf("호텔이나 집에서 휴식해 HP를 채울 수 있습니다.");
					
					gotoxy(3,14);
					printf("구멍가게에서 플레이에 도움이 되는 여러 아이템을 구매할 수 있습니다");
					
					gotoxy(3,16);
					printf("만약 돈이 다 떨어졌을 경우 장기를 팔아 기본 자금을 다시 마련할 수 있습니다.");
			
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("Page 3는 아직 업슴 ㅎ");
					gotoxy(3,3);
					printf("곧 추가될 수 있음");
					
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
	
	
	
// 공통 알고리즘
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
	
	void ing(float n)						// 로딩 (n * 1 초)
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
	
	
	
// 게임
	// 포커 함수
	void Poker_Room()
	{
		
		
		int i = 1;					// 메뉴 선택
		int key= 0;					// 키 인식
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
				gotoxy(3, 22);printf("포커방에 입장하였습니다.");
			}
			
			if(re == 1)
			{
				gotoxy(3, 22);printf("포커방 홀로 돌아왔습니다.");
			}
			
			Sleep(500);
			gotoxy(35, 23);printf("%c%c %c%c 로 이동 , 스페이스바(엔터)로 선택", 0xa1,0xe8, 0xa1,0xe9);
			gotoxy(3, 24);printf("무엇을 하시겠습니까?");
			
			
			gotoxy(24, 14);
			printf("파이브 드로우 포커 %c%c", 0xa1, 0xdb);
			gotoxy(33, 15);
			printf("세븐 포커 %c%c", 0xa1, 0xdb);
			gotoxy(38, 16);
			printf("설명 %c%c", 0xa1, 0xdb);
			gotoxy(36, 17);
			printf("나가기 %c%c", 0xa1, 0xdb);
			
			gotoxy(3, 10);printf("┏━━━━━━┓ ");
			gotoxy(3, 11);printf("┃ ?    ┃ ");
			gotoxy(3, 12);printf("┃      ┃ ");
			gotoxy(3, 13);printf("┃      ┃ ");
			gotoxy(3, 14);printf("┃   ?  ┃ ");
			gotoxy(3, 15);printf("┃      ┃ ");
			gotoxy(3, 16);printf("┃      ┃ ");
			gotoxy(3, 17);printf("┃     ?┃ ");
			gotoxy(3, 18);printf("┗━━━━━━┛ ");
			
			gotoxy(13, 10);printf("┏━━━━━━┓ ");
			gotoxy(13, 11);printf("┃ ?    ┃ ");
			gotoxy(13, 12);printf("┃      ┃ ");
			gotoxy(13, 13);printf("┃      ┃ ");
			gotoxy(13, 14);printf("┃   ?  ┃ ");
			gotoxy(13, 15);printf("┃      ┃ ");
			gotoxy(13, 16);printf("┃      ┃ ");
			gotoxy(13, 17);printf("┃     ?┃ ");
			gotoxy(13, 18);printf("┗━━━━━━┛ ");
			
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
						gotoxy(73 - j, 2); printf("┏━━━━━━┓ ");
						gotoxy(73 - j, 3); printf("┃ ?    ┃ ");
						gotoxy(73 - j, 4);printf("┃      ┃ ");
						gotoxy(73 - j, 5);printf("┃   ?  ┃ ");
						gotoxy(73 - j, 6);printf("┃      ┃ ");
						gotoxy(73 - j, 7);printf("┃     ?┃ ");
						gotoxy(73 - j, 8);printf("┗━━━━━━┛ ");
						
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
						gotoxy(73 - up, 2); printf("┏━━━━━━┓ ");
						gotoxy(73 - up, 3); printf("┃ ?    ┃ ");
						gotoxy(73 - up, 4);printf("┃      ┃ ");
						gotoxy(73 - up, 5);printf("┃   ?  ┃ ");
						gotoxy(73 - up, 6);printf("┃      ┃ ");
						gotoxy(73 - up, 7);printf("┃     ?┃ ");
						gotoxy(73 - up, 8);printf("┗━━━━━━┛ ");
						
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
			
			switch(i)					// 메뉴에 따른 이동
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
					gotoxy(3, 22);printf("포커방에서 퇴장합니다.");
					ing(0.3);
					re = 2;
					break;
			}
		}
	}

	void Show(int x, int y, int N, int T, int i)
	{
		gotoxy(x, y);				// 위 문양 출력
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
		
		gotoxy(x + 3, y + 4 + i + i);			// 아래 문양 출력
		if(T == 1)
			printf("%c%c", 0xa2, 0xbc);
		else if(T == 2)
			printf("%c%c", 0xa2, 0xbe);
		else if(T == 3)
			printf("%c%c", 0xa1, 0xdf);
		else if(T == 4)
			printf("%c%c", 0xa2, 0xc0);
		
		gotoxy(x + 2, y + 2 + i);					// 숫자
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
		printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("스페이스 바, 엔터 키로 게임으로 돌아가기");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
			
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("포커방에서는 다양한 규칙의 포커 게임을 할 수 있습니다.");
					gotoxy(3,4);
					printf("방향키와 스페이스 바(엔터)를 사용합니다.");
					
					gotoxy(3,6);
					printf("파이브 드로우 포커는 혼자서 족보와 패를 비교해 게임을 하는 1인용과");
					gotoxy(3,7);
					printf("                     딜러와 패를 비교해 게임을 하는 2인용이 있습니다.");
					
					
					gotoxy(3,18);
					printf("포커 게임 한 판당 HP가 6씩 감소합니다.");
					
					gotoxy(75,19);
					printf("Page 1/1");
				}
					
				/*if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("이 게임은 족보만 보고 숫자의 높낮이는 보지 않습니다.");
					gotoxy(3,3);
					printf("아래는 이 게임의 족보입니다.");
					
					gotoxy(3,5);
					printf("노 페어 : 아래에 언급되는 어느 족보에도 해당되지 않는 경우.");
					gotoxy(3,6);
					printf("          베팅 한 만큼 돈을 잃습니다.");
					gotoxy(3,8);
					printf("원 페어 : 숫자가 같은 카드 2장이 존재.");
					gotoxy(3,9);
					printf("          베팅 한 금액의 0.5배를 돌려받습니다.");
					gotoxy(3,11);
					printf("투 페어 : 원 페어가 2쌍 존재.");
					gotoxy(3,12);
					printf("          베팅 한 금액의 0.9배를 돌려받습니다.");
					gotoxy(3,14);
					printf("트리플 : 숫자가 같은 카드 3장이 존재.");
					gotoxy(3,15);
					printf("         베팅 한 금액의 3배를 얻습니다.");
					gotoxy(3,17);
					printf("스트레이트 : 숫자가 연속된 카드 5장.");
					gotoxy(3,18);
					printf("             베팅 한 금액의 20배를 얻습니다.");
					
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("플러시 : 숫자 상관없이 무늬가 같은 카드 5장.");
					gotoxy(3,3);
					printf("         베팅 한 금액의 8배를 얻습니다.");
					gotoxy(3,5);
					printf("풀 하우스 : 트리플과 원 페어가 같이 존재.");
					gotoxy(3,6);
					printf("           베팅 한 금액의 10배를 얻습니다~");
					gotoxy(3,8);
					printf("포카드 : 숫자가 같은 카드 4장.");
					gotoxy(3,9);
					printf("         베팅 한 금액의 30배를 얻습니다 ~~!!");
					
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
	
	void Poker_Five_Draw_1()							// 파이브 드로우 포커 1
	{
		int Number[6];						// 받는 카드
		int Type[6];
		
		int i, j, l;
		int key;
		
		int Poker_Count = 1;				// 포커 카운팅
		int Poker_re = 1;					// 포커 리
		
		
		Full_Clear();
		
		gotoxy(3, 22);
		printf("파이브 드로우 포커를 시작합니다.");
		
		gotoxy(0, 28);
		Sleep(0);
		
		gotoxy(3, 24);
		printf("설명을 보시겠습니까?");
			
		i = YN();						// 설명
		if(i == 1)
			Poker_Five_Draw_1_inf();
		
		while(Poker_re == 1)			// 반복 게임
		{
			int T_Number[6] = {0, 0, 0, 0, 0, 0};		// 버린 카드 초기화
			int T_Type[6] = {0, 0, 0, 0, 0, 0};
			
			int Card[6] = {0, 0, 0, 0, 0, 0};
			int point = 0;								// 점수 매 판 초기화	
			int Change[6] = {0, 0, 0, 0, 0, 0};			// 체인지 매 판 초기화
			int bet1 = 0;							// 베팅
			int bet2 = 0;
			
			Full_Clear();
			Status();
			
			for(i = 1 ; i <= 5; i++)			// 처음 카드 받기
			{
				for(j = 0; j < 70; j++)
				{
					if(73 - j != 67 - 15 * (5 - i))
					{
						Sleep(6- ((5-i) * 0.5));	// 4
						
						gotoxy(73 - j, 8); printf("┏━━━━━━┓ ");
						gotoxy(73 - j, 9); printf("┃ ?    ┃ ");
						gotoxy(73 - j, 10);printf("┃      ┃ ");
						gotoxy(73 - j, 11);printf("┃   ?  ┃ ");
						gotoxy(73 - j, 12);printf("┃      ┃ ");
						gotoxy(73 - j, 13);printf("┃     ?┃ ");
						gotoxy(73 - j, 14);printf("┗━━━━━━┛ ");
					}
					else
						break;
				}
			}
				
			while(1)							// 첫 번째 베팅
			{
				Long_Clear();
				Small_Clear();
				
				gotoxy(3, 21);printf("%d 번째 게임입니다.", Poker_Count);
				gotoxy(0, 28);
				Sleep(500);
				gotoxy(3, 23);printf("얼마를 베팅하시겠습니까?");
				gotoxy(3, 24);printf("  단위 만 (0이면 취소) ");
				
				gotoxy(70, 22);printf("%c%c %c%c %c%c  1", 0xa1,0xe8, 0xa1,0xe9, 0xa1,0xbe);
				gotoxy(70, 23);printf("%c%c %c%c %c%c 50", 0xa1,0xe7, 0xa1,0xe6, 0xa1,0xbe);
				
				gotoxy(91, 22);printf("베팅1");
				
				
				while(1)							// 베팅 키 인식
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
								if(0 <= bet1 && bet1 < floor(Money))	// floor 은 버림 함수
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
				if(bet1 == 0)						// 베팅 취소
				{
					Small_Clear();
					gotoxy(3, 22);
					printf("파이브 드로우 포커를 그만 하시겠습니까?");
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
			
			for(i = 1; i <= 5; i++)					// 카드 뽑기
			{			
				Number[i] = rand() % 9 + 6;
				Type[i] = rand() % 4 + 1;
			
				for(j=1; i-j>0; j++)		// 중복 체크
				{
					if(Number[i] == Number[i-j] && Type[i] == Type[i-j])
						i--;
				}
			}
			
			ShowCard(Number, Type, Change);				// 받은 카드 출력
			for(i = 1; i <= 5; i++)					// Change 값 초기화
				Change[i] = 0;
			
			for(i = 1; i <= 5; i++)					// 카드 바꾸기 동그라미 출력
			{
				gotoxy(12 + 15 * (i-1), 18);printf("%c%c", 0xa1, 0xdb);
				
				gotoxy(79, 16);printf("완료");
				gotoxy(80, 18);printf("%c%c", 0xa1, 0xdb);
			}
			
			gotoxy(13, 23);
			printf("%c%c %c%c 를 이용해 움직이고 스페이스바나 엔터키를 이용해 선택", 0xa1, 0xe7, 0xa1, 0xe6);
			
			i = 1;
			while(1)							// 카드 바꾸기 키 인식
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
						
			for(i = 1; i <=5; i++)				// 카드 버리기
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
								gotoxy(8 + 15 * (i - 1), 14 - j);printf("┗━━━━━━┛ ");
								
								if(13 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), 13 - j);printf("┃      ┃ ");
									
									if(Type[i] == 1 || Type[i] == 4)					// 검은 아래 문양
									{
										gotoxy(14 + 15 * (i - 1), 13 - j);
										printf("%c%c", a,b);
									}
									
									if(Type[i] == 2 || Type[i] == 3)					// 빨간 아래 문양
									{
										Set_Color(12);
										
										gotoxy(14 + 15 * (i - 1), 13 - j);
										printf("%c%c", a,b);
										
										Set_Color(15);
									}
									
									if(12 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), 12 - j);printf("┃      ┃ ");
										
										if(11 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), 11 - j);printf("┃      ┃ ");
											
											if(Type[i] == 1 || Type[i] == 4)			// 하얀 숫자 출력		
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
											
											if(Type[i] == 2 || Type[i] == 3)			// 빨간 숫자 출력		
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
												gotoxy(8 + 15 * (i - 1), 10 - j);printf("┃      ┃ ");
												
												if(9 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), 9 - j);printf("┃      ┃ ");
													
													if(Type[i] == 1 || Type[i] == 4)	// 하얀 위 문양
													{
														gotoxy(10 + 15 * (i - 1), 9 - j);	
														printf("%c%c", a,b);
													}
													if(Type[i] == 2 || Type[i] == 3)	// 빨간 위 문양
													{
														Set_Color(12);
														
														gotoxy(10 + 15 * (i - 1), 9 - j);	
														printf("%c%c", a,b);
														
														Set_Color(15);
													}
													
													if(8 - j > 0)
													{
														gotoxy(8 + 15 * (i - 1), 8 - j);printf("┏━━━━━━┓ ");
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
			
			for(i = 1; i <= 5; i++)				// 새로 뽑기, 중복 체크, 카드 가져오기
			{
				
				if(Change[i] == 1)
				{
					int a;
				
					T_Number[i] = Number[i];
					T_Type[i] = Type[i];
				
					do								// 새로 뽑기
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
					
					for(i = 1; i <=5; i++)				// 카드 가져오기
					{
						if(Change[i] == 1)
						{
							for(j = 1; j < 15; j++)
							{
								
								Sleep(25);	// 25
								
								if(8 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), j+7);printf("┗━━━━━━┛ ");
									
									if(9 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), j+6);printf("┃     ?┃ ");
										
										if(10 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), j+5);printf("┃      ┃ ");
											
											if(11 - j > 0)
											{
												gotoxy(8 + 15 * (i - 1), j+4);printf("┃   ?  ┃");
												
												if(12 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), j+3);printf("┃      ┃ ");
													
													if(13 - j > 0)
													{
														gotoxy(8 + 15 * (i - 1), j+2);printf("┃?     ┃ ");
														
														if(14 - j > 0)
														{
															gotoxy(8 + 15 * (i - 1), j+1);printf("┏━━━━━━┓ ");
															
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
			
			while(1)							// 두 번째 베팅
			{
				Long_Clear();
				
				gotoxy(3, 21);printf("두 번째 베팅시간입니다.");
				gotoxy(3, 23);printf("얼마를 베팅하시겠습니까?");
				gotoxy(3, 24);printf("  단위 만 (0이면 취소) ");
				
				gotoxy(70, 22);printf("%c%c %c%c %c%c  1", 0xa1,0xe8, 0xa1,0xe9, 0xa1,0xbe);
				gotoxy(70, 23);printf("%c%c %c%c %c%c 50", 0xa1,0xe7, 0xa1,0xe6, 0xa1,0xbe);
				
				gotoxy(91, 24);printf("베팅2");
				
				
				while(1)							// 베팅 키 인식
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
								if(0 <= bet2 && bet2 < floor(Money))	// floor 은 버림 함수
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

			ShowCard(Number, Type, Change);	// 바꾼 카드 출력
			
			// 점수 체크 시작
			{
				
				/* if(N[1] == 10 && N[2] == 11 && N[3] == 12 && N[4] == 13 && N[5] == 14)	// 백 스트레이트
				p += 20; */
				
				if(Type[1] == Type[2] && Type[1] == Type[3] && Type[1] == Type[4] && Type[1] == Type[5]) // 플러시
				{
					Card[1] = 1;
					Card[2] = 1;
					Card[3] = 1;
					Card[4] = 1;
					Card[5] = 1;
					
					point += 10;
				}
				
				{									// 스트레이트
					for(i = 1; i <= 4; i++)			// 내림차순 버블 정렬 사용
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
					
					if((Number[1] - 1) == Number[2])	// 점점 작아지는지 확인				
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
				
				for(i=1; i<=4; i++)	// 페어 종류 ~ 풀하우스
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

			gotoxy(91, 22);printf("최종 베팅 금액");
			gotoxy(95, 24);printf("%.2lf", (bet1 + bet2 * 0.8));
			
			i = Card[1] + Card[2] + Card[3] + Card[4] + Card[5];
			gotoxy(0, 28);getch();
			
			if(point != 0)						// 결과 창
			{
				{												// 결과 출력 창 그리기
					gotoxy(42 - (6 * i) - 1, 6);printf("┏");		// 맨 위
					for(j = 1; j <= 6 * i; j++)
					{
						printf("━");
					}
					printf("┓");
					
					for(j = 7; j <= 15; j++)
					{
						gotoxy(42 - (6 * i) - 1, j);printf("┃");
						for(int p = 1; p <= 6 * i; p++)
						{
							printf("  ");
						}
						printf("┃");
					}
					
					gotoxy(42 - (6 * i) - 1, 16);printf("┗");	// 맨 아래
					for(j = 1; j <= 6 * i; j++)
					{
						printf("━");
					}
					printf("┛");
				}
				
				{												// 결과 출력 카드(모양)
					l = 1;
					
					for(j = 1; j <= 5; j++)
					{
						if(Card[j] == 1)
						{
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2,  9);printf("┏━━━┓ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 10);printf("┃?     ┃ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 11);printf("┃      ┃ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 12);printf("┃   ?  ┃ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 13);printf("┃      ┃ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 14);printf("┃     ?┃ ");
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 2, 15);printf("┗━━━┛ ");
							l++;
						}
					}
				}
				
				{												// 결과 출력 카드(문양)
					l = 1;
					
					for(j = 1; j <= 5; j++)
					{
						if(Card[j] == 1)
						{
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 4, 10);		// 위 문양
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
							
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 8, 14);		// 아래 문양
							if(Type[j] == 1)
								printf("%c%c", 0xa2, 0xbc);
							else if(Type[j] == 2)
								printf("%c%c", 0xa2, 0xbe);
							else if(Type[j] == 3)
								printf("%c%c", 0xa1, 0xdf);
							else if(Type[j] == 4)
								printf("%c%c", 0xa2, 0xc0);
							
							
							gotoxy(42 - (6 * i) + (12 * (l - 1)) + 7, 12);		// 숫자
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
			
			switch(point)						// 결과
			{
				case 0:
					gotoxy(3, 22);printf("노 페어입니다.");
					gotoxy(3, 24);printf("배팅금 %d 만 원을 잃었습니다.", (bet1 + bet2));
					break;
				
				case 1:
					gotoxy(39, 7);printf("원 페어..");
					gotoxy(3, 22);printf("원 페어입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 0.5);
					gotoxy(3, 24);printf("%.2lf 만 원을 돌려받았습니다.", ((bet1 + 0.8 * bet2) * 0.5));
					break;
					
				case 2:
					gotoxy(39, 7);printf("투 페어");
					gotoxy(3, 22);printf("투 페어입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 0.9);
					gotoxy(3, 24);printf("%.2lf 만 원을 돌려받았습니다.", ((bet1 + 0.8 * bet2) * 0.9));
					break;
					
				case 3:
					gotoxy(39, 7);printf("트리플~");
					gotoxy(3, 22);printf("트리플입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 3);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 3.0));
					break;
				
				case 4:
					gotoxy(39, 7);printf("풀 하우스~~~");
					gotoxy(3, 22);printf("풀 하우스입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 10);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 10.0));
					break;
					
				case 13:
					gotoxy(39, 7);printf("풀 하우스~~~");
					gotoxy(3, 22);printf("풀 하우스입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 10);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 10.0));
					break;
					
				case 6:
					gotoxy(39, 7);printf("포 카드~~!!!!");
					gotoxy(3, 22);printf("포 카드입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 30);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 30.0));
					break;
					
				case 16:
					gotoxy(39, 7);printf("포 카드~~!!!!");
					gotoxy(3, 22);printf("포 카드입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 30);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 30.0));
					break;
					
				case 10:
					gotoxy(39, 7);printf("플러시~~");
					gotoxy(3, 22);printf("플러시입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
					break;
					
				case 11:	
					gotoxy(39, 7);printf("플러시~~");
					gotoxy(3, 22);printf("플러시입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
					break;

				case 12:
					gotoxy(39, 7);printf("플러시~~");
					gotoxy(3, 22);printf("플러시입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 8);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
					break;	
					
				case 20:
					gotoxy(39, 7);printf("스트레이트~~");
					gotoxy(3, 22);printf("스트레이트입니다.");
					Money += (float)((bet1 + 0.8 * bet2) * 20);
					gotoxy(3, 24);printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 20.0));
					break;	
			}
			
			gotoxy(0, 28);getch();
			Long_Clear();
			
			if(Money == 0)						// 0원
			{
				gotoxy(3, 21);printf("포커방에서 돈을 전부 잃으셨습니다 ㅠㅠ\n");
				Sleep(1000);
				break;
			}
			else if(Money < 1)
			{
				gotoxy(3, 21);printf("베팅 최소 금액보다 보유 금액이 모자랍니다....\n");
				Sleep(1000);
				break;
			}
			
			HP -= 6;
			if(HP <= 0)							// 체력
			{
				HP = 0;
				gotoxy(3, 21);printf("HP가 0이 되었습니다...\n");
				Sleep(1000);
				break;
			}	
			
			Status();
			gotoxy(3, 22);printf("다시 하시겠습니까?");
			
			Small_Clear();
			while(1)							// 리
			{
				
				Poker_re = YN();
				if(Poker_re == 1 || Poker_re == 2)
					break;
			}
			
			Poker_Count++;
		}
		
		gotoxy(3, 24);printf("포커방 메인홀로 돌아갑니다.");
		ing(1);
	}
		
	void ShowCard(int N[], int T[], int C[])	// 카드 출력
	{
		for(int i = 1; i <= 5; i++)
		{
			int a = 0;
			
			Set_Color(15);
			
			if(C[1] == 0 && C[2] == 0 && C[3] == 0 && C[4] == 0 && C[5] == 0)
			{
				C[1] = 1;									// 만약 카드 교체 전이면 전부 출력
				C[2] = 1;
				C[3] = 1;
				C[4] = 1;
				C[5] = 1;
			}
			
			if(C[i] == 1)									// 카드 교체 후엔 교체한 카드만 새로 출력
			{
				gotoxy(10 + 15 * (i-1), 9);				// 위 문양 출력
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
				
				gotoxy(13 + 15 * (i-1), 13);			// 아래 문양 출력
				if(T[i] == 1)
					printf("%c%c", 0xa2, 0xbc);
				else if(T[i] == 2)
					printf("%c%c", 0xa2, 0xbe);
				else if(T[i] == 3)
					printf("%c%c", 0xa1, 0xdf);
				else if(T[i] == 4)
					printf("%c%c", 0xa2, 0xc0);
				
				gotoxy(12 + 15 * (i-1), 11);			// 번호 출력
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

	void Poker_Five_Draw_1_inf()						// 파이브 드로우 포커 1 설명
	{
		int Page = 1;
		int key;
		int Change = 1;
		
		Full_Clear();
		
		gotoxy(30, 22);
		printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
		gotoxy(30, 24);
		printf("스페이스 바, 엔터 키로 게임으로 돌아가기");
		
		while(1)
		{
			if(Change == 1)
			{
				Big_Clear();
			
				if(Page == 1)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("이 게임은 5장을 받고 확인한 후 바꾸고 싶은 장 수만큼 한 번에 바꾼 후");
					gotoxy(3,3);
					printf("족보와 패를 비교해 베팅 한 만큼의 돈을 얻는 1인용 파이브 카드 드로우 포커입니다.");
					
					gotoxy(3,6);
					printf("게임 진행 과정");
					gotoxy(3,8);
					printf("카드를 받고 첫 번째 베팅을 합니다.");
					gotoxy(3,9);
					printf("그 후 바꿀 카드를 선택합니다.");
					gotoxy(3,11);
					printf("새로 카드를 받고 오픈하기 전에 두 번째 베팅을 합니다.");
						 gotoxy(3,12);
					printf("이 두 번째 베팅은 베팅한 만큼 보유 금액에서 빠져나가지만");
					gotoxy(3,13);
					printf("최종 베팅 금액에는 0.8배로 취급됩니다.");
					gotoxy(3,15);
					printf("즉 최종 베팅 금액은 (첫 번째 베팅 금액 + 0.8 * 두 번째 베팅 금액)입니다.");
					
					
					gotoxy(3,18);
					printf("포커 게임 한 판당 HP가 6씩 감소합니다.");
					
					gotoxy(75,19);
					printf("Page 1/3");
				}
					
				if(Page == 2)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("이 게임은 족보만 보고 숫자의 높낮이는 보지 않습니다.");
					gotoxy(3,3);
					printf("아래는 이 게임의 족보입니다.");
					
					gotoxy(3,5);
					printf("노 페어 : 아래에 언급되는 어느 족보에도 해당되지 않는 경우.");
					gotoxy(3,6);
					printf("          베팅 한 만큼 돈을 잃습니다.");
					gotoxy(3,8);
					printf("원 페어 : 숫자가 같은 카드 2장이 존재.");
					gotoxy(3,9);
					printf("          베팅 한 금액의 0.5배를 돌려받습니다.");
					gotoxy(3,11);
					printf("투 페어 : 원 페어가 2쌍 존재.");
					gotoxy(3,12);
					printf("          베팅 한 금액의 0.9배를 돌려받습니다.");
					gotoxy(3,14);
					printf("트리플 : 숫자가 같은 카드 3장이 존재.");
					gotoxy(3,15);
					printf("         베팅 한 금액의 3배를 얻습니다.");
					gotoxy(3,17);
					printf("스트레이트 : 숫자가 연속된 카드 5장.");
					gotoxy(3,18);
					printf("             베팅 한 금액의 20배를 얻습니다.");
					
					gotoxy(75,19);
					printf("Page 2/3");
				}
				
				if(Page == 3)
				{
					Change = 0;
					
					gotoxy(3,2);
					printf("플러시 : 숫자 상관없이 무늬가 같은 카드 5장.");
					gotoxy(3,3);
					printf("         베팅 한 금액의 8배를 얻습니다.");
					gotoxy(3,5);
					printf("풀 하우스 : 트리플과 원 페어가 같이 존재.");
					gotoxy(3,6);
					printf("           베팅 한 금액의 10배를 얻습니다~");
					gotoxy(3,8);
					printf("포카드 : 숫자가 같은 카드 4장.");
					gotoxy(3,9);
					printf("         베팅 한 금액의 30배를 얻습니다 ~~!!");
					
					gotoxy(75,19);
					printf("Page 3/3");
				}
			}
			
		//	printf("스트레이트 플러시 : 숫자가 연속되고 무늬가 같은 카드 5장\n");
		//	printf("로열 스트레이트 플러시 : 무늬가 같은 A, K, Q, J, 10\n");
			
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

	
	// 로또 함수
	void Lottery()									// 로또
	{
		int Lottery_re = 1;
		int Lottery[6];
		
		int i;
		
		system("cls");
		
		printf("복권방에 입장했습니다\n\n");
		Sleep(500);
		
		printf("설명을 보시겠습니까?\n");
		while(1)								// 설명
		{
			i = YN();
			
			if(i == 1)
				Lottery_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Lottery_re == 1)					// 반복 게임
		{
			system("cls");
			printf("현재 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n\n", HP);
			
			printf("5개 한장에 10만 원\n");
			
			printf("구매 ?\n");
			while(1)
			{
				printf("Yes 1, No 2 : ");
				scanf("%d", &i);
				if(i == 1 || i == 2)
					break;
			}
			
			if(i == 2)							// 안 사면 나감
				break;
			Money -= 10;
			
			printf("\n\n");
			
			for(i = 1; i <= 5; i++)				// 랜덤		
				Lottery[i] = rand()% 1000 + 1;
				
			for(i = 1; i <= 5; i++)				// 등수 출력
			{
				if(Lottery[i] <= 450)
				{
					printf("꽝\n");
				}
				
				else if(Lottery[i] <= 749)
				{
					printf("6등\n");
					Money += 0.5;
				}
				
				else if(Lottery[i] <= 909)
				{
					printf("5등\n");
					Money += 3;
				}
				
				else if(Lottery[i] <= 959)
				{
					printf("4등\n");
					Money += 8;
				}
				
				else if(Lottery[i] <= 989)
				{
					printf("3등~\n");
					Money += 50;
				}
				
				else if(Lottery[i] <= 999)
				{
					printf("2등~~\n");
					Money += 300;
				}
				
				else if(Lottery[i] == 1000)
				{
					printf("1등~~~!!\n");
					Money += 1000;
				}
			}	
			
			if(Money < 10)						// 돈 없음
			{
				printf("\n로또 가격보다 보유 금액이 적습니다 ㅠㅠ\n");
				Sleep(2000);
				break;
			}
			
			HP -= 3;
			if(HP <= 0)							// 체력
			{
				HP = 0;
				printf("\nHP가 0이 되었습니다...\n");
				Sleep(2000);
				break;
			}
			
			printf("\n게임 후 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n\n", HP);
			while(1)							// 리
			{
				printf("\n다시 하시겠습니까?\n");
				Lottery_re = YN();
				if(Lottery_re == 1 || Lottery_re == 2)
					break;
			}
		}
		
		printf("\n\n복권방을 퇴장합니다");
		ing(3);
	}
	
	void Lottery_inf()							// 설명
	{		
		system("cls");
		
		printf("5개에 한 장인 종이를 10만 원에 살 수 있습니다.\n");
		
		printf("아래는 각 등수에 걸릴 확률과 당첨금입니다.\n\n");
		printf("1등 0.1 %%  1000만 원\n");
		printf("2등 1   %%   300만 원\n");
		printf("3등 3   %%    50만 원\n");
		printf("4등 5   %%     8만 원\n");
		printf("5등 11  %%     3만 원\n");
		printf("6등 25  %%   0.5만 원\n\n");
		printf("꽝  54.9%%\n\n");
		
		printf("로또 한 장을 긁는데 HP가 3 소모됩니다.\n\n\n");
		
		printf("아무 버튼이나 눌러 복권방으로\n");
		getch();
		Sleep(100);
	}

	
	// 금 거래소 함수
	int Gold_Store(float Price, int *Have)			// 금 거래소
	{
		int Gold_re = 1;
		int trade = 0;
		
		int i;
		
		system("cls");
		
		printf("금 거래소에 입장했습니다\n\n");
		Sleep(500);
		
		printf("설명을 보시겠습니까?\n");
		while(1)								// 설명
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
			printf("현재 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n", HP);
			printf("금괴 %d개 보유중\n\n", *Have);
			printf("현재 금괴 1개의 구매 가격은 %.2lf 만 원\n", Price);
			printf("                판매 가격은 %.2lf 만 원입니다\n\n", Price * 0.8);
			
			while(1)								// 선택
			{
				printf("구매 1, 판매 2, 나가기 3 : ");
				scanf("%d", &i);
				
				if(i == 1 || i == 2 || i == 3)
					break;
			}
			
			
			
			switch(i)								// 각각 구매 판매 나가기
			{
				case 1:								// 구매	
					if(Money < Price)			// 돈이 없을 경우 구매 불가
					{
						printf("\n\n현재 금괴의 가격보다 보유 금액이 적어 구매할 수 없습니다.");
						ing(2);
						break;
					}
					while(1)
					{
						i = (Money / Price);
						printf("\n%d개까지 구매 가능합니다.", i);
						printf("몇 개 구매하시겠습니까? (0 입력시 취소)\n");
						printf("구매 : ");
						scanf("%d", &trade);
						
						if(trade == 0)
							break;
						if(trade <= i)
							break;
						
						printf("돈이 모자라 그만큼 살 수 없습니다 !\n");
						ing(2);
					}
					
					Money -= (float)(Price * trade);
					*Have += trade;
					HP -= (trade * 3);
					
					if(trade != 0)
						printf("\n%.2lf 만 원으로 %d개 구매하셨습니다.\n", Price * trade, trade);
					
					break;
				
				case 2:								// 판매
					if(*Have == 0)						// 가지고 있는 게 없으면 돌아감
					{
						printf("\n\n보유중인 금괴가 없습니다..");
						ing(2);
						continue;
					}
					
					while(1)
					{
						printf("몇 개 판매하시겠습니까? (0 입력시 취소)\n");
						printf("판매 : ");
						scanf("%d", &trade);
						
						if(trade <= *Have)
							break;
					}
					
					if(trade == 0)
							break;
						
					Money += (float)(Price * trade);
					*Have -= trade;
					HP -= (trade * 3);
					printf("\n%d개를 판매해 \n%.2lf 만 원을 받으셨습니다.\n", trade, Price * trade);
					
					break;
				
				case 3:
					Gold_re = 2;
			}
			
			if(HP <= 0)							// 체력
			{
				HP = 0;
				printf("\nHP가 0이 되었습니다...\n");
				Sleep(2000);
				break;
			}	
					
			if(i != 3)
				printf("\n\n금 거래소를 퇴장하시겠습니까?\n");
			
			while(i != 3)							// 금 거래소 리
			{
				i = YN();
						
				if(i == 1)
					Gold_re = 2;
						
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n금 거래소를 퇴장합니다");
		ing(3);
	}

	int Gold_Change(float *Price, int *Big)		// 금괴 가격 변동
	{
		int i = 0;
		int P_M;
		
		int one;			// 100의 자리
		int two;			// 10의 자리
		int three;			// 1의 자리
		float four;			// 0.1의 자리
		float five;			// 0.01의 자리
		
		float total = 0;
		
		if(*Big == 0)						// 대폭락
			i = rand()% 10 + 1;
		
		if(i == 10)							// ----
			*Big = 3;
		if(i == 3)
			*Big = 10;
			
		
		if(*Big == 0)						// 무난하게 랜덤
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
		
		
		if(*Big != 0)					// 대폭락
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
	
	void Gold_inf()								// 설명
	{
		system("cls");
		
		printf("처음 금괴 한 개의 가격은 1000만 원이지만\n");
		printf("날이 지날 때마다 랜덤하게 금괴의 가격이 변동합니다.\n");
		printf("금괴의 가격은 500만 원 아래로는 내려가지 않습니다.\n");
		printf("변동 가격은 -299.99 ~ +299.99 중 랜덤으로 선택됩니다.\n\n");
		printf("낮은 확률로 금괴 대폭락 이벤트가 발생합니다.\n");
		printf("발생할 경우 3일 동안 금괴의 가격이 3~400만 원씩 떨어집니다.\n");
		printf("갑자기 가격이 뛰는 경우도 있습니다.\n");
		printf("금괴의 가격은 금 거래소에서만 확인할 수 있습니다.\n");
		printf("팔 때는 수수료 때문에 0.8배로 파실 수 있습니다\n\n");
		
		printf("한 개의 금괴를 사고팔 때마다 HP가 3씩 감소합니다.\n\n\n");
		
		printf("아무 버튼이나 눌러 금 거래소로\n");
		getch();
		Sleep(100);
	}
		
		
	// 경마장 함수
	void Race()										// 경마장
	{
		int i;
		
		int Race_re = 1;
		int Race_Count = 1;				// 경마 카운팅
		
		int Horse_Select;
		int Horse_Win = 0;
		int WW = 0;
		
		int bet;
		
		system("cls");
		
		printf("경마장에 입장했습니다\n\n");
		Sleep(500);
		
		printf("설명을 보시겠습니까?\n");
		while(1)								// 설명
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
			
			printf("현재 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n\n", HP);
			printf("%d번 째 게임입니다.\n", Race_Count);
			printf("몇 번 말을 선택하시겠습니까?\n");					// 말 선택
			while(1)
			{
				printf("(0 입력시 취소) : ");
				scanf("%d", &Horse_Select);
								
				if(0 <= Horse_Select && Horse_Select <= 3)
					break;
			}
			if(Horse_Select == 0)
				break;
			
			printf("\n%d번 말에 얼마나 베팅하시겠습니까?\n", Horse_Select);					// 베팅
			while(1)
			{
				printf("(0입력시 취소) : ");
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
				printf("%d번 말이 1등입니다.", Horse_Win);
			if(Horse_Win == 12)
				printf("1번 말과 2번 말이 공동 1등입니다.");
			if(Horse_Win == 13)
				printf("1번 말과 3번 말이 공동 1등입니다.");
			if(Horse_Win == 23)
				printf("2번 말과 3번 말이 공동 1등입니다.");
			
			
			printf("\n\n\n");
			
			if(Horse_Select == 1 && Horse_Win == 12)		// 공동 1등
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 3);
				Money += (float)(bet * 3);
				WW = 1;
			}
			
			if(Horse_Select == 1 && Horse_Win == 13)
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 3);
				Money += (float)(bet * 3);
				WW = 1;
			}
			
			if(Horse_Select == 2 && Horse_Win == 12)
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 2);
				Money += (float)(bet * 2);
				WW = 1;
			}
			
			if(Horse_Select == 2 && Horse_Win == 23)
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 2);
				Money += (float)(bet * 2);
				WW = 1;
			}
			
			if(Horse_Select == 3 && Horse_Win == 13)
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 1.5);
				Money += (float)(bet * 1.5);
				WW = 1;
			}
			
			if(Horse_Select == 3 && Horse_Win == 23)
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				printf("%d 만 원을 획득했습니다 !\n\n", bet * 1.5);
				Money += (float)(bet * 1.5);
				WW = 1;
			}
			
			if(Horse_Select == Horse_Win)
			{
				WW = 1;
				if(Horse_Select == 1)						// 1번 승	
				{
					printf("1등 말을 맞추셨습니다 !!\n");
					printf("%d 만 원을 획득했습니다 !\n\n", bet * 3);
					Money += (float)(bet * 3);
				}
				
				if(Horse_Select == 2)						// 2번 승
				{
					printf("1등 말을 맞추셨습니다 !!\n");
					printf("%d 만 원을 획득했습니다 !\n\n", bet * 2);
					Money += (float)(bet * 2);
				}
				
				if(Horse_Select == 3)						// 3번 승
				{
					printf("1등 말을 맞추셨습니다 !!\n");
					printf("%.2lf 만 원을 획득했습니다 !\n\n", bet * 1.5);
					Money += (float)(bet * 1.5);
				}
			}
			if(WW == 0)
			{
				printf("1등 말을 맞추지 못하였습니다..\n\n");			// 패배
			}
			
			HP -= 5;
			
			if(Money == 0)									// 0원
			{
				printf("경마장에서 돈을 전부 잃으셨습니다 ㅠㅠ\n");
				Sleep(2000);
				break;
			}
			else if(Money < 1)
			{
				printf("베팅 최소 금액보다 보유 금액이 모자랍니다....\n");
				Sleep(2000);
				break;
			}
			
			printf("게임 후 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n", HP);
			while(1)							// 리
			{
				printf("\n다시 하시겠습니까?\n");
				Race_re = YN();
				if(Race_re == 1 || Race_re == 2)
					break;
			}
			
			Race_Count++;
		}
		printf("\n\n경마장을 퇴장합니다");
		ing(3);
	}
	
	void Race_inf()								// 설명
	{
		system("cls");
		
		printf("세 마리의 말 중에 어떤 말이 가장 먼저 들어오나 맞추는 게임입니다.\n");
		printf("트랙은 총 30칸으로 이루어져 있으며 2초마다 0~5칸씩 랜덤으로 움직입니다.\n");
		printf("좀 더 빠르게 들어오는 말이 1위 판정을 가집니다.\n");
		printf("동시에 들어올 경우 공동 1위로 칩니다.\n\n");
		
		printf("각각 말은 턴당 최대 속도가 조금 다릅니다.\n");
		printf("1번 말은 0~4칸\n");
		printf("2번 말은 0~5칸\n");
		printf("3번 말은 0~6칸\n");
		printf("1등 말을 맞출 경우 각각 베팅 금액의 3배, 2배, 1.5배를 획득합니다.\n\n");
		
		printf("경마 한 게임당 HP가 5씩 감소합니다.\n\n");
		
		printf("아무 버튼이나 눌러 경마장으로\n");
		getch();
		Sleep(100);
	}

	int Race_Start(int Select)					// 경마 시작
	{
		int i;
		int j;
		int Win = 0;
		
	//	int HM;
		int Horse[4] = {0, 0, 0, 0};
		
			
		while(Win == 0)
		{
			int Fast[4] = {0, 0, 0, 0};
			
			system("cls");								// 보드 초기화
						
			printf("S----------------------------F\n");	// 30칸
			
			for(i = 1; i <= 3; i++)
			{
				if(i == 1)												// 1번 말은
				{
					Fast[1] = rand()%5;									// 0칸 ~ 4칸
					Horse[1] += Fast[1];
					if(Fast[1] != 0 && Fast[1] != 4)
						Fast[1] = 1;
				}
				if(i == 2)												// 2번 말은
				{
					Fast[2] = rand()%6;									// 0칸 ~ 5칸
					Horse[2] += Fast[2];
					if(Fast[2] != 0 && Fast[2] != 5)
						Fast[2] = 1;
				}
				if(i == 3)												// 3번 말은
				{
					Fast[3] = rand()%7;									// 0칸 ~ 6칸
					Horse[3] += Fast[3];
					if(Fast[3] != 0 && Fast[3] != 6)
						Fast[3] = 1;
				}
		
				for(j = 1; j <= Horse[i]; j++)							// 칸 이동
					printf(" ");
				
				if(Horse[i] >= 30)										// 결승 선은 못 넘음
				{
					for(j = 30; j <= Horse[i]; j++)
						printf("\b");
				}
				
				printf("%d", i);
				
				if(Horse[i] >= 29)										// 결승 선 통과
					printf("★\n");
				else
					printf("\n");
					
			}
			printf("S----------------------------F\n\n");	// 30칸	
			
			if(Horse[1] >= 29 || Horse[2] >= 29 || Horse[3] >= 29)		// 승리 조건
			{
				if(Horse[1] > Horse[2] && Horse[1] > Horse[3])		// 1번 말 승리
					Win = 1;
				
				if(Horse[2] > Horse[1] && Horse[2] > Horse[3])		// 2번 말 승리
					Win = 2;
					
				if(Horse[3] > Horse[1] && Horse[3] > Horse[2])		// 3번 말 승리
					Win = 3;
				
				if(Win == 0)
				{
					if(Horse[1] == Horse[2])							// 1&2 공동
						Win = 12;
						
					if(Horse[1] == Horse[3])							// 1&3 공동
						Win = 13;
						
					if(Horse[2] == Horse[3])							// 2&3 공동
						Win = 23;
				}
			}
			
			for(i = 1; i <= 3; i++)
			{
				if(Win == 0 && Fast[i] > 3)
					printf("%d번 말이 빠르게 질주합니다 !!\n", i);
				if(Win == 0 && Fast[i] == 0)
					printf("%d번 말이 기어갑니다....\n", i);
			
			}
			Sleep(850);										// 라운드마다 확인
		}
		
		return Win;
	}
	
	
	
// 시설
	// 호텔 함수
	void Hotel()
	{	
		int Hotel_Count	= 0;		// 호텔 날짜 카운팅
		int i;
		
		system("cls");
		printf("호텔에 입장했습니다\n\n");
		Sleep(500);
		
		printf("현재 보유 %.2lf 만 원 \n", Money);
		printf("HP : %d\n", HP);
		printf("\n호텔에서 휴식을 취하시겠습니까?\n");
		printf("하루 쉬고 HP+100, 돈 - 100 만\n");				
		while(1)
		{
			i = YN();
			
			if(i == 1)
			{
				printf("\n\n휴식중");
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
				printf("돈이 없어서 호텔에 더 머무를 수 없습니다.\n");
				break;
			}
			printf("하루 더 쉬시겠습니까?\n");
			Hotel_Count++;
		}
		
		if(Hotel_Count != 0)
			Day += (Hotel_Count-1);
		
		printf("\n호텔에서 퇴장합니다");
		ing(3);
		
	}
	
	
	// 구멍가게 함수
	void Hole()
	{
		int i;
		int Many;
		
		int Hole_re = 1;
		
		system("cls");
		printf("구멍가게에 입장했습니다\n\n");
		Sleep(500);
		
		printf("상품의 설명을 보시겠습니까?\n");
		while(1)								// 설명
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
			
			printf("현재 보유 %.2lf 만 원 \n", Money);
			printf("HP : %d\n", HP);
			
			printf("\n상품 이름   | 가격\n\n");
			printf("1. 쌍화탕    1000 만 원\n");
			printf("2. 호루라기   200 만 원\n");
			
			printf("\n\n\n");
			printf("무엇을 구매? (0 입력시 취소) : ");
			
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
						printf("보유 금액이 모자라 구매하실 수 없습니다!.");
						ing(1);
						break;
					}
					
					Many = Hole_Purchase(&Many, i);
					if(Many == 0)
						break;
					
					printf("\n\n%d 만 원으로 %d개 구매하셨습니다.", (Many * 1000), Many);
					Money -= (Many * 1000);
					Drink += Many;
					break;
					
				case 2:
					i = (Money / 200);
					
					if(Money < 200)
					{
						printf("보유 금액이 모자라 구매하실 수 없습니다!.");
						ing(1);
						break;
					}
					
					Many = Hole_Purchase(&Many, i);
					if(Many == 0)
						break;
					
					printf("\n\n%d 만 원으로 %d개 구매하셨습니다.", (Many * 200), Many);
					Money -= (Many * 200);
					Whistle += Many;
					break;
			}
			printf("\n\n구멍가게를 퇴장하시겠습니까?\n");
			while(1)							// 구멍가게 리
			{
				i = YN();
						
				if(i == 1)
					Hole_re = 2;
				
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n구멍가게를 퇴장합니다");
		ing(3);
	}
	
	void Hole_inf()
	{
		system("cls");
		printf("\n\n\n");
		
		printf("1. 쌍화탕   : 최대 HP를 30 늘려줍니다.\n");
		printf("2. 호루라기 : 80%% 확률로 깡패를 내쫓습니다.\n");
		
	//	printf("3. \n");
		
		printf("\n\n\n");
		printf("아무 버튼이나 눌러 구멍 가게로\n");
		getch();
		Sleep(100);
	}
	
	int Hole_Purchase(int *M, int Can)
	{
		printf("\n%d개까지 구매 가능 : ", Can);
		while(1)
		{
			scanf("%d", &*M);
			if(0 <= *M && *M <= Can)
			break;
		}
		return *M;
	}
	
	
	// 은행 함수
	void Bank()
	{
		int i;
		int Choice;
		int Bank_re = 1;
		int s;
		
		
		
		system("cls");
		
		printf("은행에 입장했습니다\n\n");
		Sleep(500);
		
		printf("설명을 보시겠습니까?\n");
		while(1)								// 설명
		{
			i = YN();
			
			if(i == 1)
				Bank_inf();
			
			if(i == 1 || i == 2)
				break;
		}
		
		while(Bank_re == 1)										// 은행 반복
		{
			int Bank_Storage = 0;
			
			for(i = 1; i <= 9; i++)
			{
				if(Saving[i] == 1)
					Bank_Storage += Ten_Square(i);
			}
			system("cls");
			
			printf("현재 보유 %.2lf 만 원\n", Money);
			printf("저금한 금액 %d 만 원\n\n", Bank_Storage);
			
			printf("무엇을 하시겠습니까 ?\n");
			while(1)
			{
				printf("1. 저금, 2. 출금, 3. 나가기 : ");		// 선택
				scanf("%d", &Choice);
				if(0 <= Choice && Choice <= 3)
					break;
			}
			
			printf("\n\n");
			
			switch(Choice)
			{
				case 1:														// 저금
					for(s = 1; s <= 9; s++)
					{
						if(Saving[s] == 0)
							printf("%10d 만 원 저금 가능\n", Ten_Square(s));
					}
					printf("\n\n");
					while(1)
					{
						printf("얼마를 저금하시겠습니까?\n");
						printf("(0 입력시 취소) : ");
						scanf("%d", &s);
						
						if(s == 0)
							break;
						
						if(s > Money)					// 돈이 모자랄 때
						{
							printf("입력한 금액보다 보유 금액이 적어 저금할 수 없습니다.\n\n");
							continue;
						}
						
						if(Saving[Ten_Divide(s)] == 0)
						{
							printf("\n%d 만 원 저금하셨습니다.\n", s);
							Money -= s;
							Saving[Ten_Divide(s)] = 1;
							Sleep(1000);
							break;
						}
						else
							printf("%d 만 원은 이미 저금한 적이 있습니다.\n\n", s);
					}
					break;
					
				case 2:												// 출금
					for(s = 1; s <= 9; s++)
					{
						if(Saving[s] == 1)
							printf("%10d 만 원 출금 가능\n", Ten_Square(s));
					}
					printf("\n\n");
					printf("얼마를 출금하시겠습니까?\n");
					while(1)
					{
						printf("(0 입력시 취소) : ");
						scanf("%d", &s);
						
						if(s == 0)
							break;
						
						if(Saving[Ten_Divide(s)] == 1)
						{
							printf("%d 만 원 출금하셨습니다.\n", s);
							Money += s;
							Saving[Ten_Divide(s)] = 0;
							Sleep(1000);
							break;
						}
						else
							printf("%d 만 원은 저금한 적이 없습니다.\n", s);
					}
					break;
						
				case 3:												// 나가기
					Bank_re = 2;
			}
		}
		
		printf("\n\n은행을 퇴장합니다");
		ing(3);
	}
	
	void Bank_inf()
	{
		system("cls");
		
		printf("은행은 돈을 저금하고 하루에 10%의 이자를 받을 수 있습니다.\n");
		printf("이자는 은행에서 불어나지 않고 아닌 보유 금액에 직접 추가됩니다.\n");
		printf("저금은 10 만, 100 만, 1000 만 같은 10의 제곱수로만 가능합니다.\n");
		printf("각 금액당 한번밖에 저금할 수 없습니다.\n");
		printf("ex)1111 만 원 저금 가능, 1112 만 원 저금 불가, 3201 만 원 저금 불가\n\n\n");
		
		printf("아무 버튼이나 눌러 은행으로\n");
		getch();
		Sleep(100);
	}
	

	// 부동산
	void Real_Estate()
	{
		int i;
		int Real_Estate_re = 1;
		
		system("cls");
		
		printf("부동산에 입장했습니다\n\n");
		Sleep(500);
		
		printf("설명을 보시겠습니까?\n");
		while(1)								// 설명
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
			printf("현재 보유 %.2lf 만 원\n\n", Money);
			switch(House_Have)
			{
				case 0:								// 집 구매
					printf("집을 구매하시겠습니까?\n");
					printf("가격 2000 만 원\n");
					while(1)						// 선택
					{
						i = YN();
						
						if(i == 1 || i == 2)
							break;
					}
					
					if(i == 1)
					{
						if(Money < 2000)
						{
							printf("돈이 모자라 집을 구매할 수 없습니다.\n");
							ing(1);
						}
						if(Money >= 2000)
						{
							printf("\n\n2000 만 원으로 집을 구매하였습니다.\n");
							ing(1);
							House_Have = 1;
							Money -= 2000;
						}
					}
					break;
					
				case 1:
					printf("집을 판매하시겠습니까?\n");
					printf("가격 2000 만 원\n");
					while(1)						// 판매
					{
						i = YN();
						
						if(i == 1 || i == 2)
							break;
					}
					if(i == 1)
					{
						printf("집을 판매해 2000 만 원을 획득했습니다.\n");
						ing(1);
						House_Have = 0;
						Money += 2000;
					}
					break;
			}
			
			
			printf("\n\n부동산을 퇴장하시겠습니까?\n");
			while(1)							// 부동산 리
			{
				i = YN();
						
				if(i == 1)
					Real_Estate_re = 2;
				
				if(i == 1 || i == 2)
					break;
			}
		}
		printf("\n\n부동산을 퇴장합니다");
		ing(3);
	}
	
	void Real_Estate_inf()
	{
		system("cls");
		
		printf("부동산에서는 자신만의 집을 구매할 수 있습니다.\n");
		printf("집은 한 종류밖에 없습니다.\n");
		printf("돈이 없을 때 집을 팔 수도 있습니다.\n\n");
		
		printf("집은 HP를 최대로 회복시켜줍니다.\n\n");
		
		printf("아무 버튼이나 눌러 부동산으로\n");
		getch();
		Sleep(100);
	}
	
	
// 기타
	// 아이템 확인
	void Item_Check()
	{
		system("cls");
		
		printf("1. 쌍화탕   %d개 보유중\n", Drink);
		printf("2. 호루라기 %d개 보유중\n", Whistle);
	//	printf("3. 
		
		printf("\n\n\n");
		printf("아무 버튼이나 눌러 메뉴로\n");
		getch();
		Sleep(100);
	}
	
	
	// 집
	void House()
	{
		int House_Count = 0;
		int i;
		
		system("cls");
		
		printf("집에 들어왔습니다\n\n");
		Sleep(500);
		
		printf("현재 보유 %.2lf 만 원 \n", Money);
		printf("HP : %d\n", HP);
		printf("최대 HP : %d\n", (100 + 30 * Drink));
		printf("\n집에서 휴식을 취하시겠습니까?\n");
		printf("하루 쉬고 HP 최대 회복\n");				
		while(1)
		{
			i = YN();
			
			if(i == 1)
			{
				printf("\n\n휴식중");
				ing(3);
				
				HP = (100 + 30 * Drink);
				
				system("cls");
			}	
			
			if(i == 2)
				break;
			
			printf("하루 더 쉬시겠습니까?\n");
			House_Count++;
		}
		
		if(House_Count != 0)
			Day += (House_Count-1);
		
		printf("\n집에서 나갑니다");
		ing(3);
		
	}
	
	
	
	
	
	