#include <stdio.h>
#include <windows.h>            // gotoxy, system, sleep
#include <time.h>               // srand
#include <conio.h>              // getch()
#include <math.h>               // floor()

float money = 500.00;   // money


void Edge();    // Drawing Function
void Big_Clear();
void Long_Clear();
void Small_Clear();
void Loading_Clear();
void Full_Clear();


void gotoxy(int x, int y);  // Common Function
void ing(float n);
int YN();

void Poker_Room();                              // Poker Function
void Poker_Room_inf();                      
void Show(int x, int y, int N, int T, int i);
void Poker_Five_Draw_1();
void Poker_Five_Draw_1_inf();
void ShowCard(int N[], int T[], int C[]);



int main(void){
    srand(time(NULL));
    system("mode con cols=115 lines=30");	// Screen resizing
	system("cls");
    Edge();
    Poker_Room();
    
}

// Drawing Function
void Edge(){
	int i;
    int h = 0xa2;
    int v = 0xcc;
	
	for(i = 0; i <= 42; i++){			// Main Horizontal
		gotoxy(i * 2, 0);
		printf("%c%c", h, v);
		
		gotoxy(i * 2, 20);
		printf("%c%c", h, v);
		
		gotoxy(i * 2, 26);
		printf("%c%c", h, v);
		
		gotoxy(i * 2, 28);
		printf("%c%c", h, v);
	}
		
	for(i = 0; i<= 28; i++){				// Main Vertical
		gotoxy(0, i);
		printf("%c%c", h, v);
		
		gotoxy(84, i);
		printf("%c%c", h, v);
	}
	
	for(i = 0; i < 10; i++){			// Select Horizontal
		gotoxy(88 + i * 2, 20);
		printf("%c%c", h, v);
		
		gotoxy(88 + i * 2, 26);
		printf("%c%c", h, v);
	}
	
	for(i = 0; i < 6; i++){				// Select Vertical
		gotoxy(88, 20 + i);
		printf("%c%c", h, v);
		
		gotoxy(106, 20 + i);
		printf("%c%c", h, v);
	}
}

void Status(){
	gotoxy(88, 3);printf("Money($) :  %.2lf     ", money);
}
	
void Set_Color(int Text){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Text | 0);
}

void Big_Clear(){
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
	
void Long_Clear(){
	gotoxy(2, 21);printf("                                                                                  ");
	gotoxy(2, 22);printf("                                                                                  ");
	gotoxy(2, 23);printf("                                                                                  ");
	gotoxy(2, 24);printf("                                                                                  ");
	gotoxy(2, 25);printf("                                                                                  ");
}
	
void Small_Clear(){
	gotoxy(90, 21);printf("                ");
	gotoxy(90, 22);printf("                ");
	gotoxy(90, 23);printf("                ");
	gotoxy(90, 24);printf("                ");
	gotoxy(90, 25);printf("                ");
}
	
void Loading_Clear(){
	gotoxy(2, 27);printf("                                                                                  ");
}
	
void Full_Clear(){
	Edge();
	Big_Clear();
	Long_Clear();
	Small_Clear();
	Loading_Clear();
	Status();
}

// Common Function	
void gotoxy(int x, int y){	// gotoxy
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void ing(float n){						// Loading (n second)
	gotoxy(2, 27);
	for(int i = 0; i < 41; i++){
		printf("%c%c", 0xa1, 0xe1);
		Sleep(15 * n);
	}
}
	
int YN(){							// Yes or No  1 -> Yes, 2 -> No
	int yesONE_noTWO = 1;
	int key;
	
	gotoxy(91, 23);
	printf("Yes      No %c%c", 0xa1, 0xdb);
		
	while(1){
		gotoxy(88 + yesONE_noTWO * 8, 23);
		printf("\b%c%c", 0xa1, 0xdc);
		gotoxy(2, 21);
		
		gotoxy(0, 28);
		key = getch();
		if(key == 224){
			key = getch();
			gotoxy(88 + yesONE_noTWO * 8, 23);
			printf("\b%c%c", 0xa1, 0xdb);
			switch(key){
				case 75:
					if(yesONE_noTWO == 2)
						yesONE_noTWO--;
					
					break;
				
				case 77:
					if(yesONE_noTWO == 1)
						yesONE_noTWO++;
				
						break;
					
				default:
					break;
			}
		}
		
		if(key == 32 || key == 13)
			break;
	}
	
	return yesONE_noTWO;
}

	
void Poker_Room(){
    
    int key = 0;                // For getch();
    int re = 0;                 // 0 -> First Time, 1 -> Re Enter.
    int select_menu = 1;        // menu select
    int time = 0;
    int Number, Type;           // Card of Background
    int moving_first = 0;             // Moving Card Location 1
    int moving_second = -1;           // Moving Card Location 2
    
    while(re < 2){           // re -> 2, End
        Full_Clear();
        
        if(re == 0){
            gotoxy(3, 22);printf("You entered the poker room.");
        }
        if(re == 1){
            gotoxy(3, 22);printf("You backed to the poker room.");
        }
        
 		Sleep(500);
		gotoxy(35, 23);printf("%c%c %c%c to move , Space Bar(Enter) to select", 0xa1,0xe8, 0xa1,0xe9); //   ← →   Special Characters
		gotoxy(3, 24);printf("What will you do?");

     	gotoxy(27, 14);printf("Five Draw Poker %c%c", 0xa1, 0xdb);
		gotoxy(31, 15);printf("Seven Poker %c%c", 0xa1, 0xdb);
		gotoxy(31, 16);printf("Information %c%c", 0xa1, 0xdb);
		gotoxy(38, 17);printf("Exit %c%c", 0xa1, 0xdb);   
        
            
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
        
        
        
        while(1){       // while Until select menu. if select -> break
            gotoxy(44, 13 + select_menu);
			printf("\b%c%c", 0xa1, 0xdc);
            
            //gotoxy(0, 28);
            
			if(kbhit()){         // If press Anything -> return 1, else -> return 0
				gotoxy(0, 28);key = getch();
				if(key == 224){              // Direction key recognition
					key = getch();
					gotoxy(44, 13 + select_menu);
					printf("\b%c%c", 0xa1, 0xdb);
					switch(key){
						case 72:
							if(select_menu > 1)
								select_menu--;
							break;
						
						case 80:
							if(select_menu < 4)
								select_menu++;
							break;
							
						default:
							break;
					}
				}
				if(key == 32 || key == 13)      // 32 = Space bar , 13 = Enter
					break;
			}
            else{               // If press nothing
                time++;
                
				if(time == 300){                    // Card of Right
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(15, 11, Number, Type, 1);      // x y location -> Top Pattern
				}                
 				if(time == 1300){                   // Card of Left
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(5, 11, Number, Type, 1);
				}               
                
                if(time % 100 == 0){
					gotoxy(73 - moving_first, 2);printf("┏━━━━━━┓ ");
					gotoxy(73 - moving_first, 3);printf("┃ ?    ┃ ");
					gotoxy(73 - moving_first, 4);printf("┃      ┃ ");
					gotoxy(73 - moving_first, 5);printf("┃   ?  ┃ ");
					gotoxy(73 - moving_first, 6);printf("┃      ┃ ");
					gotoxy(73 - moving_first, 7);printf("┃     ?┃ ");
					gotoxy(73 - moving_first, 8);printf("┗━━━━━━┛ ");
					
					moving_first++;
					
					if(moving_first == 35 && moving_second == -1)           // moving_first = 70 -> End, moving_first = 35 -> half -> second one start
						moving_second = 0;
					if(moving_first > 70){                      // moving_first reset
						moving_first = 0;
						
						Number = rand() % 14 + 1;
						Type = rand() % 4 + 1;
						Show(5, 3, Number, Type, 0);
					}
				}

				if(moving_second >= 0 && time %100 == 0){
					gotoxy(73 - moving_second, 2);printf("┏━━━━━━┓ ");
					gotoxy(73 - moving_second, 3);printf("┃ ?    ┃ ");
					gotoxy(73 - moving_second, 4);printf("┃      ┃ ");
					gotoxy(73 - moving_second, 5);printf("┃   ?  ┃ ");
					gotoxy(73 - moving_second, 6);printf("┃      ┃ ");
					gotoxy(73 - moving_second, 7);printf("┃     ?┃ ");
					gotoxy(73 - moving_second, 8);printf("┗━━━━━━┛ ");
					
					moving_second++;
					
					if(moving_second > 70){                     // moving_second reset
						moving_second = 0;
						
						Number = rand() % 14 + 1;
						Type = rand() % 4 + 1;
						Show(5, 3, Number, Type, 0);
						
					}
				}
                    
                
  				if(time >= 2000)            // time reset
					time = 0;              
                
                
            }
            
            
            
            
            
        }
  		switch(select_menu){					// select
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
				gotoxy(3, 22);printf("Exit the poker room.");
				ing(0.3);
				re = 2;
				break;
		}
        
        
        
        
    }
}

void Poker_Room_inf(){
	int Page = 1;
	int key;
	int Changing = 1;   // Changing = 1 -> Clear
	
	Full_Clear();
		
	gotoxy(30, 22);
	printf("%c%c %c%c to Page turning", 0xa1, 0xe7, 0xa1, 0xe6);
	gotoxy(30, 24);
	printf("Press Space bar or Enter key to back to play");    
       
	while(1){
		if(Changing == 1){
			Big_Clear();
		
			if(Page == 1){
				Changing = 0;
				
				gotoxy(3,2);
				printf("In the poker room, you can play poker with various rules.");
				gotoxy(3,4);
				printf("Use the arrow keys and space bar (enter).");
				
				gotoxy(3,6);
				printf("We have only Five Draw Poker now");
				
				//gotoxy(3,18);
				//printf("Each poker game loses 6 HP.");
				
				gotoxy(75,19);
				printf("Page 1/1");
			}
				
			if(Page == 2){
				Changing = 0;
			
				
				gotoxy(75,19);
				printf("Page 2/3");
			}
			
			if(Page == 3){
				Changing = 0;

				gotoxy(75,19);
				printf("Page 3/3");
			}
		}
		
		gotoxy(0, 28);
        
		key = getch();
		if(key == 224){
			key = getch();
			if(key == 75){
				if(1 < Page && Page <= 3){
					Page--;
					Changing = 1;
				}
			}
			if(key == 77){
				if(1 <= Page && Page < 3){
					Page++;
					Changing = 1;
				}
			}
		}
		
		if(key == 32 || key == 13)
			break;
	}
	ing(0.5);        
}

void Show(int x, int y, int N, int T, int Big){        // x y -> location  , N T -> Card  , Big 1 -> Long Card, Big 0 -> Short Card
	gotoxy(x, y);				            // Top Pattern
	if(T == 1)
		printf("%c%c", 0xa2, 0xbc);
	else if(T == 2){
		Set_Color(12);
		printf("%c%c", 0xa2, 0xbe);
	}
	else if(T == 3){
		Set_Color(12);                  // Set_Color(12) -> Red  , Set_Color(15) -> White // Color of Font
		printf("%c%c", 0xa1, 0xdf);
	}else if(T == 4)
		printf("%c%c", 0xa2, 0xc0);
	
	gotoxy(x + 3, y + 4 + Big * 2);			// Bottom Pattern
	if(T == 1)
		printf("%c%c", 0xa2, 0xbc);
	else if(T == 2)
		printf("%c%c", 0xa2, 0xbe);
	else if(T == 3)
		printf("%c%c", 0xa1, 0xdf);
	else if(T == 4)
		printf("%c%c", 0xa2, 0xc0);
	
	gotoxy(x + 1, y + 2 + Big);					// Number
	if(N <= 10)
        printf("%2d", N);
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
    
void Poker_Five_Draw_1(){
    int Number[5];              // number
    int Type[5];                // type
    
    int key;
    
    int Poker_count = 1;        // n time's game
    

	Full_Clear();
		
	gotoxy(3, 22);
	printf("Start Five Draw Poker.");
		
	gotoxy(0, 28);
	Sleep(0);
		
	gotoxy(3, 24);
	printf("Would you like to see the Manual?");
    
	if(YN() == 1){                  // Manual
        ing(0.5);
		Poker_Five_Draw_1_inf();    
    }
        
    while(1){                   // You can replay game
 		int T_Number[6] = {};		// discarded card reset
		int T_Type[6] = {};
		
		int point = 0;				    // At every game , score reset
		int Change[5] = {1,1,1,1,1};			// Change reset
        int hh = 1;
 
		int bet1 = 0;							// Bet
		int bet2 = 0; 
        
        Full_Clear();
               
		for(int i = 1 ; i <= 5; i++){			// First Draw
			for(int j = 0; j < 70; j++){
				if(73 - j != 67 - 15 * (5 - i)){
					Sleep(5- ((5-i) * 0.5));	// 4
					
					gotoxy(73 - j, 8); printf("┏━━━━━━┓ ");
					gotoxy(73 - j, 9); printf("┃ ?    ┃ ");
					gotoxy(73 - j, 10);printf("┃      ┃ ");
					gotoxy(73 - j, 11);printf("┃   ?  ┃ ");
					gotoxy(73 - j, 12);printf("┃      ┃ ");
					gotoxy(73 - j, 13);printf("┃     ?┃ ");
					gotoxy(73 - j, 14);printf("┗━━━━━━┛ ");
				}
				else break;
			}
		}
        
        
        while(1){							// Bet First Time
			Long_Clear();
			Small_Clear();
			
			gotoxy(3, 21);printf("%d times Game", Poker_count);
			gotoxy(0, 28);
            Sleep(500);
			gotoxy(3, 23);printf("How much will you bet on?");
			gotoxy(3, 24);printf("(0 to exit)");
			
			gotoxy(70, 22);printf("%c%c %c%c %c%c  1", 0xa1,0xe8, 0xa1,0xe9, 0xa1,0xbe);
			gotoxy(70, 23);printf("%c%c %c%c %c%c 50", 0xa1,0xe7, 0xa1,0xe6, 0xa1,0xbe);
			
			gotoxy(91, 22);printf("Bet 1");
			
			
			while(1){							// Bet First time
				gotoxy(97, 22);printf("%d", bet1);
				gotoxy(0, 28);
				key = getch();
				if(key == 224)
				{
					key = getch();
					gotoxy(97, 22);printf("         ");
					
					switch(key){
						case 72:
							if(0 <= bet1 && bet1 < floor(money))	// floor to rounding off
								bet1++;
							break;
							
						case 75:
							if(bet1 <= 50)
								bet1 = 0;
							else if(50 <= bet1 && bet1 <= floor(money))
								bet1 -= 50;
							break;
							
						case 77:
							if(floor(money) - 50 < bet1)
								bet1 = floor(money);
							else if(0 <= bet1 && bet1 <= floor(money) - 50)
								bet1 += 50;
							break;
						
						case 80:
							if(1 <= bet1 && bet1 <= floor(money))
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
			if(bet1 == 0){						// Cancel Bet
				Small_Clear();
				gotoxy(3, 22);
				printf("Would you like to stop Five Draw Poker?");
				if(YN() == 1)
					break;
				else continue;
			}
			else{
				money -= bet1;
				Status();
				break;
			}
		}
        
		if(bet1 == 0)
			break;
       
		for(int i = 0; i <= 4; i++){					// Draw Card
			Number[i] = rand() % 9 + 6;
			Type[i] = rand() % 4 + 1;
		
			for(int j = 1; i-j >= 0; j++)		// Check 
			{
				if(Number[i] == Number[i-j] && Type[i] == Type[i-j])
					i-- ;
			}
		}        
        
        ShowCard(Number, Type, Change);
        
        for(int i = 0; i <= 4; i++) // Change reset
            Change[i] = 0;
            
 		for(int i = 0; i < 5; i++){					// Create Circle to Change
			gotoxy(12 + 15 * i, 18);printf("%c%c", 0xa1, 0xdb);
			
			gotoxy(75, 16);printf("Complete");
			gotoxy(80, 18);printf("%c%c", 0xa1, 0xdb);
		}
		
		gotoxy(20, 23);
		printf("%c%c %c%c to Move, Space Bar or Enter key to Select", 0xa1, 0xe7, 0xa1, 0xe6);
			           
            
        for(int select = 0; ; ){							// Card Change
			if(select <= 4){
				gotoxy(13 + 15 * select, 18);printf("\b%c%c", 0xa1, 0xdc);
				gotoxy(2, 21);
			}
			else if(select == 5){
				gotoxy(81, 18);printf("\b%c%c", 0xa1, 0xdc);
			}
			
			gotoxy(0, 28);
			key = getch();
			if(key == 224){
				key = getch();
				if(select <= 4){
					gotoxy(13 + 15 * select, 18);printf("\b%c%c", 0xa1, 0xdb);
				}
				else if(select == 5){
					gotoxy(81, 18);printf("\b%c%c", 0xa1, 0xdb);
				}
				
				switch(key){
					case 75:
						if(0 < select && select <= 5)
							select--;
						break;
					
					case 77:
						if(0 <= select && select < 5)
							select++;
						break;
						
					default:
						break;
				}
			}
				
			if(key == 13 || key == 32){         // Press Space Bar or Enter key
				if(select < 5){
					if(Change[select] == 0){			// Create V
						Change[select] = 1;
						gotoxy(12 + 15 * select, 16);
						printf("%c%c", 0xa1, 0xee);
					}
					else if(Change[select] == 1){		// Delete V
						Change[select] = 0;
						gotoxy(12 + 15 * select, 16);
						printf("  ");
					}
				}
				if(select == 5)
					break;
			}
		}
        gotoxy(2, 16);printf("                                                                                  ");     //  Delete Circle
        gotoxy(2, 18);printf("                                                                                  ");	        
        
        
		for(int i = 0; i < 5; i++){				// Card Remove
			if(Change[i] == 1){
				int a, b;
				
				switch(Type[i]){        // 1 -> Spade , 2 -> Heart , 3 -> Diamond , 4 -> Clover
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
				
				for(int j = 0; j < 15; j++){
			
                    Sleep(20);	// 20
					
					if(15 - j > 0){
						gotoxy(8 + 15 * i, 15 - j);printf("          ");
						
						
						if(14 - j > 0){
							gotoxy(8 + 15 * i, 14 - j);printf("┗━━━━━━┛ ");
							
							if(13 - j > 0){
								gotoxy(8 + 15 * i, 13 - j);printf("┃      ┃ ");
								
                                
								if(Type[i] == 2 || Type[i] == 3)			// Change to Red Color		
									Set_Color(12);                                
                                
								gotoxy(13 + 15 * i, 13 - j);                // Bottom Pattern
								printf("%c%c", a,b);
                                
                                Set_Color(15);

								
								if(12 - j > 0){
									gotoxy(8 + 15 * i, 12 - j);printf("┃      ┃ ");
									
									if(11 - j > 0){
										gotoxy(8 + 15 * i, 11 - j);printf("┃      ┃ ");
										
										if(Type[i] == 2 || Type[i] == 3)	// Change to Red Color
											Set_Color(12);
                                            
										gotoxy(11 + 15 * i, 11 - j);		// Middle Number
										if(Number[i] <= 10)
											printf("%2d", Number[i]);
										if(Number[i] == 11)
											printf(" J");
										if(Number[i] == 12)
											printf(" Q");
										if(Number[i] == 13)
											printf(" K");
										if(Number[i] == 14)
											printf(" A");                                        
										
                                        Set_Color(15);
										
										if(10 - j > 0){
											gotoxy(8 + 15 * i, 10 - j);printf("┃      ┃ ");
											
											if(9 - j > 0){
												gotoxy(8 + 15 * i, 9 - j);printf("┃      ┃ ");
                                                
												if(Type[i] == 2 || Type[i] == 3)	// Change to Red Color
													Set_Color(12);
                                                    
												gotoxy(10 + 15 * i, 9 - j);	        // Top Pattern
												printf("%c%c", a,b);
                                                
                                                Set_Color(15);
												
												
												if(8 - j > 0){
													gotoxy(8 + 15 * i, 8 - j);printf("┏━━━━━━┓ ");
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
        

		for(int i = 0; i < 5; i++){				// 새로 뽑기, 중복 체크, 카드 가져오기
			if(Change[i] == 1){
				T_Number[i] = Number[i];
				T_Type[i] = Type[i];
			
				do{								// 새로 뽑기
					int finish = 0;
					
					Number[i] = rand()% 9 + 6;
					Type[i] = rand() % 4 + 1;	
					
					for(int j = 0; j < 5; j++)
					{
						if(i != j){
							if(Number[i] == Number[j] && Type[i] == Type[j])
								finish = 1;
						}
					}
					
					for(int j = 0; j < 5; j++)
					{
						if(Number[i] == T_Number[j] && Type[i] == T_Type[j])	// T
							finish = 1;
					}
						
				}while(finish == 1);
				
				//for(int i = 0; i < 5; i++){				// 카드 가져오기
					if(Change[i] == 1){
						for(int j = 1; j < 15; j++){
							
							Sleep(25);	// 25
							
							if(8 - j > 0)
							{
								gotoxy(8 + 15 * i, j+7);printf("┗━━━━━━┛ ");
								
								if(9 - j > 0)
								{
									gotoxy(8 + 15 * i, j+6);printf("┃     ?┃ ");
									
									if(10 - j > 0)
									{
										gotoxy(8 + 15 * i, j+5);printf("┃      ┃ ");
										
										if(11 - j > 0)
										{
											gotoxy(8 + 15 * i, j+4);printf("┃   ?  ┃");
											
											if(12 - j > 0)
											{
												gotoxy(8 + 15 * i, j+3);printf("┃      ┃ ");
												
												if(13 - j > 0)
												{
													gotoxy(8 + 15 * i, j+2);printf("┃ ?    ┃ ");
													
													if(14 - j > 0)
													{
														gotoxy(8 + 15 * i, j+1);printf("┏━━━━━━┓ ");
														
														if(15 - j > 0)
														{
															gotoxy(8 + 15 * i, j);printf("          ");
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
				//}
			}
		}	        
        
        
        
        
        
        
        
        
        
        
        
         
        /*for(int i = 0; i <= 4; i++){
            if(Change[i] == 1){
                T_Number[i] = Number[i];        // Save discarded card ( To prevent duplication )
                T_Type[i] = Type[i];
                
                Number[i] = rand() % 9 + 6;
                Type[i] = rand() % 4 + 1;
            
                for(int j = 1; i-j >= 0; j++)		// Check 
                {
                    if(Number[i] == Number[i-j] && Type[i] == Type[i-j])
                        i--;
                    else if(Number[i] == T_Number[j] && Type[i] == T_Type[j]){
                        i--;
                    }
                }
            }
        }*/
        
 /*     Number[0] = 13;       // FOR TEST
        Number[1] = 12;
        Number[2] = 11;
        Number[3] = 10;
        Number[4] = 9;
        Type[0] = 1;
        Type[1] = 1;
        Type[2] = 1;
        Type[3] = 1;
        Type[4] = 1;*/
        
        ShowCard(Number, Type, Change);
        
        
        // Scoring Start
        
        if(Type[0] == Type[1] && Type[0] == Type[2] && Type[0] == Type[3] && Type[0] == Type[4])  // Flush
            point += 10;
			
 		{									// Straight
			for(int i = 0; i <= 3; i++)			// Descending Bubble Sort
			{                                   
				for(int j = 0; j <= 3-i; j++)
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
			
			if((Number[0] - 1) == Number[1]){	// Check if it gets smaller				
                if((Number[1] - 1) == Number[2]){
					if((Number[2] - 1) == Number[3]){
						if((Number[3] - 1) == Number[4])
                            point += 20;
					}
				}
			}
		}  
        
      	for(int i = 0; i <= 3; i++){	// Kind of Pair, Full House
			for(int j = 1; (i+j) <= 4; j++){
				if(Number[i] == Number[i+j])
					point++;
			}
		}
        
        
        switch(point){						// Result
				case 0:
					gotoxy(3, 22);printf("High Card.");
					break;
				
				case 1:
					gotoxy(3, 22);printf("Pair.");
					break;
					
				case 2:
					gotoxy(3, 22);printf("Two Pair.");
					break;
					
				case 3:
					gotoxy(3, 22);printf("Three of a kind.");
					break;
				
				case 4:
				case 13:
					gotoxy(3, 22);printf("Full House.");
					break;
					
				case 6:
				case 16:
					gotoxy(3, 22);printf("Four of a kind.");
					break;
					
				case 10:
				case 11:	
				case 12:
					gotoxy(3, 22);printf("Flush.");
					break;	
					
				case 20:
					gotoxy(3, 22);printf("Straight.");
					break;	
		}
        gotoxy(3,23);printf("point is %d",point);
        
        
        
        getchar();
        getchar();
    }
    
}

void Poker_Five_Draw_1_inf(){
	int Page = 1;
	int key;
	int Changing = 1;   // Changing = 1 -> Clear
	
	Full_Clear();
		
	gotoxy(30, 22);
	printf("%c%c %c%c to Page turning", 0xa1, 0xe7, 0xa1, 0xe6);
	gotoxy(30, 24);
	printf("Press Space bar or Enter key to back to play");    

	while(1){
		if(Changing == 1){
			Big_Clear();
            Changing == 0;
		
			if(Page == 1){
				
				gotoxy(3, 2); printf("This game is played alone.");
				gotoxy(3, 3); printf("After receiving and checking 5 cards,");
                gotoxy(3, 4); printf("change the number of cards you want to change at once.");
				gotoxy(3, 5); printf("You can compare genealogy and hand to get the money you bet");
				
                gotoxy(3, 7); printf("Game Progression");
                
				gotoxy(3, 8); printf("1. Receive the cards and place your first bet. (Can't Check the Cards)");
				gotoxy(3, 10); printf("2. Check the cards and select the cards to replace.");
				gotoxy(3, 12); printf("3. After receiving new cards, you place a second bet before checking.");
                gotoxy(3, 14); printf("4. This second bet will be taken out of the reserve as much as the bet is placed,");
				gotoxy(3, 15); printf("   but will be treated as 0.8 times the final bet");
				gotoxy(3, 17); printf("5. In other words, the final bet amount is");
				gotoxy(3, 18); printf("   first bet amount + 0.8 * second bet amount");                            
				
				gotoxy(75,19);
				printf("Page 1/3");
			}
				
			if(Page == 2){
                //gotoxy(3,2);printf("Each poker game loses 6 HP.");
                
				gotoxy(3,4);printf("This game only looks at genealogy, not numbers.");
				gotoxy(3,5);printf("Below is the genealogy of this game.");
				
				gotoxy(3,7);printf("High Card : If it does not apply to any genealogy");
				gotoxy(3,8);printf("            You lose money as much as you bet.");
                
				gotoxy(3,10);printf("Pair : Two cards with the same number exist");
				gotoxy(3,11);printf("       Get back 0.5 times the wager amount.");
                
				gotoxy(3,13); printf("Two Pair : Two pairs of two cards of the same number");
				gotoxy(3,14);printf("            Get back 0.9 times the wager amount..");
                
				gotoxy(3,16);printf("Three Of A Kind : Three cards with the same number exist.");
				gotoxy(3,17);printf("                  Get 3 times the amount you bet on.");
	
				
				gotoxy(75,19);
				printf("Page 2/3");
			}
			
			if(Page == 3){
                gotoxy(3, 2);printf("Straight : Five consecutive cards");
				gotoxy(3, 3);printf("           Get 10 times your wager amount.");
                
                gotoxy(3, 5);printf("Flush : There are 5 cards with the same pattern regardless of the number.");
				gotoxy(3, 6);printf("        Get 15 times your wager amount.");	
                
                gotoxy(3, 8);printf("Full House : Three Of A Kind and Pair exist simultaneously");
				gotoxy(3, 9);printf("             Get 25 times your wager amount.");	
                
                gotoxy(3, 11);printf("Four Of A Kind : Four cards with the same number");
				gotoxy(3, 12);printf("                 Get 50 times your wager amount.");	
                
                
                
				gotoxy(75,19);
				printf("Page 3/3");
			}
		}
		
		gotoxy(0, 28);
        
		key = getch();
		if(key == 224){
			key = getch();
			if(key == 75){
				if(1 < Page && Page <= 3){
					Page--;
					Changing = 1;
				}
			}
			if(key == 77){
				if(1 <= Page && Page < 3){
					Page++;
					Changing = 1;
				}
			}
		}
		
		if(key == 32 || key == 13)
			break;
	}
	ing(0.5); 
    
}

void ShowCard(int N[], int T[], int C[]){	// Print Card
	for(int i = 0; i < 5; i++){
		
		Set_Color(15);
		
		if(C[i] == 1){									// Print Only replaced cards
			gotoxy(10 + 15 * i, 9);				// Top Pattern
			if(T[i] == 1)
				printf("%c%c", 0xa2, 0xbc);
			else if(T[i] == 2){
				Set_Color(12);
				printf("%c%c", 0xa2, 0xbe);
			}
			else if(T[i] == 3){
				Set_Color(12);
				printf("%c%c", 0xa1, 0xdf);
			}
			else if(T[i] == 4)
				printf("%c%c", 0xa2, 0xc0);
			
			gotoxy(13 + 15 * i, 13);			// Bottom Pattern
			if(T[i] == 1)
				printf("%c%c", 0xa2, 0xbc);
			else if(T[i] == 2)
				printf("%c%c", 0xa2, 0xbe);
			else if(T[i] == 3)
				printf("%c%c", 0xa1, 0xdf);
			else if(T[i] == 4)
				printf("%c%c", 0xa2, 0xc0);
			
			gotoxy(12 + 15 * i, 11);			// Number
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
