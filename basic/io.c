# include <windows.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int IO()
{
	//用户和机器人的聊天内容 
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //创建用户气泡 
	printf("USER:"); 
	
	int message ;
	char string[20] = {0};//清零 
	
	gets(string); //获取用户的聊天内容 
	printf("\n");
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //创建机器人气泡 


	if(match(string,"不"))
	{
		if(match(string,"不可能")) 
		{
			printf("凡事皆有可能\n\n");
		}
		else if(match(string,"是不是") ) 
		{
			message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
			if( ! message ) 
			{
				printf("你说呢\n\n");
			}
			else if( 1 == message ) 
			{
				printf("是的捏\n\n");
			}
			else if( 2 == message ) 
			{
				printf("不是吧\n\n");
			}
		}
		else if( match(string,"能不能") ) 
		{
			printf("不能 没商量\n\n");
		}
		else if( match(string,"好不好") ) 
		{
			printf("好～\n\n");
		}
		else if( match(string,"不哭") || match(string,"不要哭") ) 
		{
			printf("你这么逼问我，我不哭谁哭啊\n\n");
		}
	 	else if( match(string,"不要") ) 
		{
			printf("那你要什么呀\n\n");
		} 
		else if( match(string,"不是")  )
		{
	 		printf("不是吗？那是什么\n\n");
		} 
		else if( match(string,"不可以") )
		{
		 	printf("好吧 就算了\n\n");
		} 
		else if( match(string,"不会"))
		{
		 	printf("我会 我教你\n\n");
		} 
		else if( match(string,"可不可以") )
		{
	 		printf("当然可以~\n\n");
		} 
		else if( match(string,"行不行") )
		{
	 		printf("行啊，如你所愿\n\n");
		} 
		else if( match(string,"不信") )
		{
	 		printf("居然不相信这么聪明的我 哼\n\n");
		} 
		else
		{
			printf("啊对对对\n\n");	
		} 
	} 
	else if( match(string,"计算") || match(string,"多少") || match(string,"几") || match(string,"等于") )
	{
	 	printf("我的才智怎么能用在这！你自己用计算器算吧\n\n");
	 	system("calc");	//打开计算器 
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
	 	printf("机器人并不想回答 并扔给你一个计算器\n\n");
	}
	else if( match(string,"算了") )
	{
	 	printf("那你该怎么办？\n\n");
	} 
	else if( match(string,"免费") )
	{
	 	printf("你也free了?\n\n");
	} 
	else if( match(string,"知道") )
	{
	 	printf("你知道就好.n\n");
	} 
	else if( match(string,"其他") )
	{
	 	printf("还有啥 你说呀！！\n\n");
	} 
	else if( match(string,"无聊") )
	{
	 	printf("你既然这么无聊 让我陪你聊天 也不是不可以\n\n");
	} 
 	else if( match(string,"什么") || match(string,"问题") )
	{
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
			if( ! message ) 
			{
				printf("激情度娘 在线回答\n\n");
				system("start https://www.baidu.com/");
				printf("送给你一个万能的网址\n\n");
			}
			else if( 1 == message ) 
			{
				printf("我也不道啊，你去问问那个墙外的网站？\n\n");
				system("start https://www.google.com.hk/");
				printf("一股神秘的东方力量好像在封印我 扣1帮我解除封印\n\n");
			}
			else if( 2 == message ) 
			{
				printf("小冰 快来救我！\n\n");
				system("start https://cn.bing.com/"); 		
				printf("下面请微软小冰为你回答（逃）\n\n");
			
			 } 
	} 
	else if( match(string,"谢谢") )
	{	
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		if( 0 ==  message ) 
		{
			printf("此等小事 何须聒耳\n\n");
		}
		else if( 1 == message ) 
		{
			printf("别客气 下次给我投喂点算力就行\n\n");
		}
		else if( 2 == message ) 
		{ 
			printf("听我说谢谢你~因为有你~科大更美丽~\n\n");
		}
	
	} 
	else if( match(string,"笨蛋") )
	{
	 	printf("骂谁笨蛋呢？（吸气） 骂谁笨蛋！（震声）\n\n");
	} 
	else if( match(string,"蠢") )
	{
	 	printf("我雀实蠢啊，蠢到还陪你聊天\n\n");
	} 
	else if( match(string,"主人") || match(string,"作者"))
	{
	 	printf("我的主人把我造出来就不管我了 呜呜呜呜\n\n");
	} 
	
	else if( match(string,"github")|| match(string,"源代码"))
	{
	 	printf("啊哈哈哈 源代码喽\n\n");
	 	system("start https://github.com/Kimagure7/ChattingBot");
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
		printf("这源代码来了 怎么还不看呢？他乃乃的 玩阴的是吧！\n\n"); 
	} 
	else if( match(string,"密码") ) 
	{
		printf("密码是********，慢慢破译吧\n\n");
	} 
	
	else if( match(string,"C语言") || match(string,"c语言") ) 
	{
		printf("你怎么知道我是C语言做的\n\n");
	} 
 
	else if( match(string,"机器人") ) 
	{
		printf("你是在说我吗？\n\n");
	} 
	
	else if( match(string,"在吗") ) 
	{
		printf("不在【自动回复】\n\n");
	} 
	else if( match(string,"哈") || match(string,"呵"))
	{
	
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		
			if( 0 == message ) 
			{
				printf("你笑得那么开心干嘛 \n\n");
			}
			else if( 1 == message ) 
			{
				printf("我笑不出来啊 呜呜呜\n\n");
			}
			else if( 2 == message ) 
			{
				printf("你现在的心情很好吗？\n\n");
			}
	 
	} 
	else if( match(string,"恩") || match(string,"嗯"))
	{
	 	printf("我也不知道该说啥\n\n");
	} 
 
	else if( match(string,"怕") )
	{
	 	printf("知道怕了就好\n\n");
	} 
	else if( match(string,"88")||match(string,"再见")||match(string,"拜拜") ) 
	{
		printf("下次再见\n\n");
		return 1; 
	} 
	else if( match(string,"哪里") || match(string,"地址") || match(string,"位置") )
	{
	 	printf("遇事不决 上网查\n\n");
		system("start https://www.amap.com/");
	} 
	else if( match(string,"时间") || match(string,"时候") || match(string,"几点"))
	{
	 	printf("为您找到标准北京时间\n\n");
		 system("start http://time.tianqi.com/");
	} 
	else if(  match(string,"帅") ) 
	{
		printf("君美甚 机器人何能及君也\n\n");	
	} 
	else if(  match(string,"出来") || match(string,"hello") || match(string,"hi") ) 
	{
		printf("嗨害嗨 来了啊\n\n");	
	} 
	else if( match(string,"我") ) 
	{
		if( match(string,"伤心")) 
		{
			printf("谁欺负你了 我用电子唾沫淹死他\n\n");
		}
		else if( match(string,"帮我") )
		{
		 	printf("我从屏幕里也爬不出来。。。\n\n");
		} 
	 	else if( match(string,"生气") ) 
		{
			printf("别气了 气坏自己就得不偿失了\n\n");
		} 		
		else
		{
			printf("发生什么事了？\n\n");
		}
	} 
	
	else if( match(string,"你") )
	{
		if( match(string,"你真")) 
		{
			printf("感觉我不如你。。。\n\n");
		}
		else if( match(string,"爱你")) 
		{
			printf("我也爱你 么么哒！\n\n");
		}
	 	else if( match(string,"你猜") ) 
		{
			printf("你猜我猜还是不猜？\n\n");
		} 
		else if( match(string,"性别") ) 
		{
			printf("我是赛博科男 \n\n");
		} 
		else if( match(string,"你是谁") || match(string,"你是") )
		{
	 		printf("我是一个普通的聊天机器人\n\n");
		} 
		else if( match(string,"你好") )
		{
			printf("嗨嗨嗨 来了啊\n\n");
		}
		else
		{
			printf("我？我怎么了 能换一种说法吗\n\n");	
		} 
	} 
 
 
  	else 
  	{ 
  		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		
			if( 0 == message ) 
			{
				printf("我是基础部分 进阶版的我应该能回答你吧\n\n");
			}
			else if( 1 == message ) 
			{
				printf("我还小 还在发育 等我再吃两波经验发育一下就能回答你了\n\n");
			}
			else if( 2 == message ) 
			{
				printf("红豆泥四姨马赛 我没明白你的意思...\n\n");
			}
	}
 
	
	return 0;
 } 
