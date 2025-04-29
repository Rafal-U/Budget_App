Aplikacja budżetowa (Budget app) - is a simple application that helps you control your personal budget
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Budget App was build using C++ technology in CodeBlocks compiler.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Description

This simple console application is designed for regular users to enable clear control over the user's personal budget. To use the application correctly, you must create
an account and then log in. Thanks to the ability to add transactions and display them along with the balance for a given time period, the user has a clear insight into
their finances, making it easier for them to save money or allocate it. The application was created in Polish language.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Table of contents

Main menu
	Registration
	Login
User menu
	Adding operations
	Displaying operations and balance
	Changing password
	Files
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	Main menu
	
	There are three options in the main menu: register, log in close the program. The user navigates the menu by typing characters from the keyboard next to the option
	and confirming them with the Enter key. If a different character or too many characters are entered, a message is displayed and the user is asked to try entering the
	corresponding digits again.

		Registration
		
		During registration, the user is asked to enter first the name and then surname. Both must be longer than one letter and cannot contain numbers or space, but in
		case of an error, the user receives a message and must enter the name again. In the next stage, the user must provide a login consisting of at least 5 characters
		and no spaces. Then they are asked to come up with and enter a password. The password must contain at least six characters, two uppercase and lowercase letters,
		two digits and no spaces. Of course, both when entering the login and password, error control has been introduced, thanks to which the user will not enter
		unreadable data or a login that already exists. The login and password are the most important in registration, because they are needed to log in, so at the end
		of the registration process the user is asked to confirm all the data that is displayed to them. Entering the letter t or T confirms, while any other character
		rejects the data and cancels the registration. Cancellation of registration is also possible at any stage of entering data, by entering the number 0.
	
		Login
	
		By logging in, user is asked to enter the login and password for their account. If a non-existent login is entered, a message is displayed and the user is
		taken to the main menu. The user has three attempts to enter the correct password, after which they are returned to the main menu. If both of these data match
		the saved information, access to further functions in the user menu is provided.
	
	User menu
	
	The user menu gives the user seven options to choose from. Adding transactions and displaying the balance according to transactions for specific time periods. There
	is also an option to change the password for the logged in user and of course log the user out, after which the user returns to the main menu. The selection method
	and error checking works as in the main menu.

		Adding operations
		
		A single transaction contains elements such as: transaction ID, logged in user ID date, description, amount. Depending on the selected option, there are two
		types of transactions: income and expense. The transaction ID is an element invisible to the user similarly to the ID of the logged-in user. The latter is used
		to assign the operation to a specific person. When adding a transaction, it is determined automatically. First, the user selects the option when the transaction
		occurred from the submenu. They can select the current date option or another datee, which must be entered manually in the YYYY-MM-DD form. This date must be
		from at least 01.01.2000 to at most the last day of the current month. If the date is correct, the user is asked to provide a description,  which can be either
		one word or a whole sentence. Then, the amount must be entered in the form of a floating-point number, which will be rounded to two decimal places. Finally, the
		entered data is displayed and the user is asked to confirm it or cancel adding the transaction. The user can also cancel the process earlier if they enter 0 at
		any of the stages. The approved transaction is saved for the logged-in user.
	
		Displaying operations and balance
		
		The user has three options for displaying transaction details:
		current month - from the first day of the current month to the current date
		last month - from the first to the last day of the previous month from the current date
		date range - the user selects the time period. Here, the dates must be entered manually in the YYYY-MM-DD form. First, the user is asked for the start date of
		the time period, then the end date. The process of entering the time range can be canceled by entering 0. The start date cannot be greater than the end date, 
		about which the user will be informed if he enters such a time period.
		After defining the time period for which transactions are to be displayed, you can finally see them. From the top, incomes are shown sorted by date with all the
		details as the date, amount and description. After all incomes, expenses are shown in the same form. At the end, you can see the sum of incomes and expenses for
		a given time period and the balance. Each transaction is assigned a serial number so that it can be seen more easily. This number is not the transaction ID.
		Pressing any key returns you to the user menu. Note! If a date is later than the current date was entered when adding a transaction, it will not be displayed in
		the current month's transaction display option until the current date is equal to it or the entered date is in the past. The user is informed about this when
		entering a future date when adding an operation. To also see this date, you must define the time period in which it will be included.
	
		Changing password
		
		After selecting the option to change the password of the logged-in user, a request to enter a new password is displayed along with the criteria. If the password
		meets the requirements, the user is asked to confirm or cancel this operation. They can also cancel by entering the number 0 instead of the new password.
		
	Files
	
	Data such as income, expenses and user data are saved in .xml files. After starting the program, the appropriate data is loaded, which allows for saving the entered
	data or its changes.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------