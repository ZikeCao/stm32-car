实验器材:
	MiniSTM32F103开发板V3版本
	
实验目的:
	学习外部中断的使用
	
硬件资源:
	1,DS0(连接在PA8),DS1(连接在PD2)
	2,按键KEY0(PC5)/KEY1(PA15)/KEY_UP(PA0,也称之为WK_UP)
	
实验现象:
	本实验,利用外部中断，实现与实验2类似的效果，即:通过开发板上载有的3个按钮（KEY_UP、KEY0
	、KEY1），来控制板上的2个LED（DS0和DS1），其中KEY0控制DS0，按一次亮，再按一次，就灭。
	KEY1控制DS1，效果同KEY0。KEY_UP则同时控制	DS0和DS1，按一次，他们的状态就翻转一次。
	
注意事项:
	1,不要把1820和PA0的跳线帽跳上,否则可能导致按键"不灵". 
	   

					正点原子@ALIENTEK
					2014-3-06
					广州市星翼电子科技有限公司
					电话：020-38271790
					传真：020-36773971
					购买：http://shop62103354.taobao.com
					http://shop62057469.taobao.com
					公司网站：www.alientek.com
					技术论坛：www.openedv.com
              