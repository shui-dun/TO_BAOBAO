#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void maze_enter()
{
	system("color 0F");
	printf("\
************************************************************************************************************************\
**     **********************     *********          *********                          ***                           **\
**     **********************     ******     ******     *****************************   ***  ***************************\
**      ********************      ****      ********      ***************************   ***  ***************************\
**   **  ******************  **   ***     ************     *************************    ***  ***************************\
**   **  ******************  **   ***    **************    ***********************     ****  ***************************\
**   **   ****************   **   ***   ****************   ***********************    *****  ***************************\
**   ***  ****************  ***   ***  ******************  **********************    ******  ***************************\
**   ***  ****************  ***   ***  ******************  ********************    ********  ***************************\
**   ****  **************  ****   ***  ******************  *******************    *********  ***************************\
**   ****  **************  ****   ***  ******************  *******************    *********  ***************************\
**   *****  ************  *****   ***  ******************  ******************    **********  ***************************\
**   ******  **********  ******   ***  ******************  ****************    ************  ***************************\
**   ******   ********   ******   ***                      ***************    *************                           **\
**   ******   ********   ******   ***                      **************    **************                           **\
**   *******   ******   *******   ***  ******************  ************    ****************  ***************************\
**   *******    ****    *******   ***  ******************  ************   *****************  ***************************\
**   ********   ****   ********   ***  ******************  **********     *****************  ***************************\
**   *********  ****  *********   ***  ******************  **********   *******************  ***************************\
**   **********  **   *********   ***  ******************  *********    *******************  ***************************\
**   **********  **   *********   ***  ******************  ********    ********************  ***************************\
**   ***********     **********   ***  ******************  *******   **********************  ***************************\
**   ************   ***********   ***  ******************  ******    **********************  ***************************\
**   **************************   ***  ******************  ****     ***********************  ***************************\
**   **************************   ***  ******************  ***    *************************  ***************************\
**   **************************   ***  ******************  **   ***************************  ***************************\
**   **************************   ***  ******************  **   ***************************  ***************************\
**   **************************   ***  ******************  **                          ****                           **\
**   **************************   ***  ******************  ********************************  ***************************\
************************************************************************************************************************\
");
	FILE *fp = fopen("D:\\从_前_慢.txt", "w");
	fprintf(fp,"\
\n\
记得早先少年时\n\
大家诚诚恳恳\n\
说一句 是一句\n\
\n\
清早上火车站\n\
长街黑暗无行人\n\
卖豆浆的小店冒着热气\n\
\n\
从前的日色变得慢\n\
车，马，邮件都慢\n\
一生只够爱一个人\n\
\n\
从前的锁也好看\n\
钥匙精美有样子\n\
你锁了 人家就懂了\n\
");
	fclose(fp);
	Sleep(3000);
}