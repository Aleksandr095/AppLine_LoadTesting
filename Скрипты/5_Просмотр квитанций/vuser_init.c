vuser_init()
{
		web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB=\"/>",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_start_transaction("����");

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=58", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		LAST);
	
	lr_end_transaction("����", LR_AUTO);

	web_set_sockets_option("SSL_VERSION", "2&3");
//
//	web_add_cookie("SRCHUID=V=2&GUID=422240F17A5F4911A6BB8CC46069374E&dmnchg=1; DOMAIN=iecvlist.microsoft.com");
//
//	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");
//
//	web_add_cookie("SRCHUSR=DOB=20200510; DOMAIN=iecvlist.microsoft.com");
//
//	web_add_header("UA-CPU", 
//		"AMD64");

//	web_url("iecompatviewlist.xml", 
//		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=text/xml", 
//		"Referer=", 
//		"Snapshot=t7.inf", 
//		"Mode=HTML", 
//		LAST);

	lr_think_time(5);
	
	return 0;
}
