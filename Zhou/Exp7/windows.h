int CDECL MessageBoxPrintf (TCHAR * szCaption, TCHAR * szFormat, ...)
	//TCHAR就是宽字符，你学过C++应该知道CHAR,TCHAR就是CHAR的两倍长度，用来兼容UNICODE的，至于UNICODE和ANSI的区别，你自己去查了。CDECL这个是C语言函数的默认调用惯例，调用惯例是什么，就是操作系统如何调用这个函数，包含了如何保存参数如何返回值等等，具体可以去查。
	{
	TCHAR szBuffer [1024] ;
	va_list pArgList ;//这里提一些必须的东西，va这个开头的宏都是处理可变参数列表的，什么是可变参数列表，意思就是可以变长的参数列表，这个在WINDOWS下用得非常多，比如printf的函数，里面用类似很多%d的格式控制，也有实际输出的内容，都是作为函数的参数，具体有多少要看实际情况，所以可变参数列表在这里就起作用了。
	//va_list就是申明一个可变参数列表的变量
	//
	va_start (pArgList, szFormat) ;//va_start用于初始化可变参数列表，具体的效果就是把szFormat这个可变参数列表的第一个参数地址赋给了pArgList
	
_vsntprintf (szBuffer, sizeof (szBuffer) / sizeof (TCHAR), 
	szFormat, pArgList) ;
	////这个很简单，就是把szFormat和pArgList格式成字符串放在szBuffer里了
	//
	va_end (pArgList) ;//把pArgList清0，这个只是为了程序的规范。
	//
	return MessageBox (NULL, szBuffer, szCaption, 0) ;
	//显示一个内容为szBuffer标题为szCaption的默认对话框，只有一个确定的那种
	}
	//
	int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow) 
	{
	int cxScreen, cyScreen ;
	//
	cxScreen = GetSystemMetrics (SM_CXSCREEN) ;
	cyScreen = GetSystemMetrics (SM_CYSCREEN) ;//取得屏幕的宽高
	//
	MessageBoxPrintf (TEXT ("ScrnSize"), 
	TEXT ("The screen is %i pixels wide by %i pixels high."),
cxScreen, cyScreen) ;//调用上面的那个函数,TEXT用于转换为UNICODE
	return 0 ;
	} 
