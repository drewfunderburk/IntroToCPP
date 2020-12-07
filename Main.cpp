#include <iostream>

void BinarySearch(int rangeMin, int rangeMax)
{
	// Minimum value
	int left = rangeMin;

	// Maximum value
	int right = rangeMax;

	// Search guess
	int guess = 0;

	while (left <= right)
	{
		// Update guess to the middle of left and right
		guess = (left + right) / 2;

		// Ask if the guess is right
		std::cout << "Is your number " << guess << "?\n";
		std::cout << " [1] Yes\n [2] No\n> ";
		int input = 0;
		std::cin >> input;
		std::cout << std::endl;

		// If we've guessed right, dab on them and return
		if (input == 1)
		{
			std::cout << "HA! GOT 'EEM!\n\n";
			std::cout << R"V0G0N(
				
            ...M.D:~~~~:8:~:8 ..                                                
       . ..$.:~~~~:~~~~~~~~~~~.:.                                               
       .+Z8~~~::~~~~:Z8~~~~I:~~:M                                               
     .D::~~~~OO:~~~~~~~:~~~:~~~~~=                                              
   .?,~~~~~~~~~~~~~~~~~~~~~~~~~~~~N                                             
  .N=~:O,~~~~::~~~~~~~~~~~~~~~~~~~:                                             
. .::~~~~~:?~:~~~~~~~~~~~~~~~~~~~~~D                                   ......$$.
.+~~~~~~~,~~~~~:,~~~~~~~~~~~~~~~~~~M                                  ?MN?.~~=~=
D:~~:~:M~~~:M,~~~~~~~::~~~~~~~~~~~~Z                         ...O:~~~~~~~~~~~~:.
.~~O~~~~~..~~~~~:$O.~~~~~~~~~~~~~~,                           :~~~~~~~~~~~~~+~? 
~~~~~~~~M:~~:,M,~~~~~~~~~~~~~~~~~:7.                         :~~~~~~~~~~~~++M.. 
+~~~~~~M~~~..~~~~M,::,.N~~~~~~~~~M.                        .,~~~~~~~~=+~7I,7    
:~~~~~~~~~?~~~~~+,::::::.,~~~~~:N.                   ....,.~~~~~~~+=+++=D.      
,:O~~~~~..~~~~~~O:::::::::8~~~~M.                    ..Z:~~~~~~~~+=?7M...       
M~~~~~~~:~~:I..O..::.O::::,:~~~M...   ..           ..M~~~~~~~.M.=: .            
..~~~~~:~~:.:::::8::$OD::::,:~~M,~~~~~:M.        ..,~~~~~~,?....                
..,~~~~~~~,::::::~M:,N8D,:::.~~~~:78,,+M.    ...M:~~~~~?. .                     
  .N=~~~~~,.::+D:::N:::88.:,:~:,,~~~~~~~~~::~MM~~~~~N                           
  .. M.:~~:O::N8O:::.~,:::,$~+,:~~~~~~~~~~~~~~~D,M...                           
            M::N8O.7~:~:8:~.::~~~~++++=+~~~~=:N.                                
            .~,:.D8.~~~~:O.:~~.M+N$+=77I==?M....                                
              .M.,.:~~~:M~~~~+...MDD?77MI7.                                     
            ..M~~~:.~:?,~~~~D?7+I7777777$7.                                     
            .M:~~~,N..~~~~,.~:+7?777777?:..                                     
            .,~~I::M:~~~~+::~~~I7M$NO,.                                         
            .:~M~.,~~~~~M~~~~~~:77777N,.                                        
            .M~:M~~~~~~M~~~~~~~,777777D..                                       
               ?~~~~~:D~~~~~~~.?7777777O.                                       
               :~~~~~M7$=:~:~Z7777777777Z                                       
             .$~~~~~N$7$7Z....7777777777$..                                     
            ..~~,.M77$D.      D7777777777I.                                     
            ....~~.....       M$7777777777~                                     
                              M77777777777N                                     
                             .I$7777777777I                                     
                            .$7777777777777.                                    
                            .I7777777$77777=                                    
                            M77IM,:~~~:,MI7=                                    
                            $?::~~~~~~~~:~=                                     
                            M~~~~~~~~~~~~:M                                     
                           .:~~~~~~~~~~~~=.                                     
                         . 8=~M~~~~~~~~::7.                                     
                          M~~:~=,Z8$~~,~~+.                                     
                          ............... .             
				")V0G0N";
				std::cout << "\n\n\n";
			return;
		}

		// Ask for higher or lower
		std::cout << "Is your number higher or lower than " << guess << "?\n";
		std::cout << " [1] Higher\n [2] Lower\n> ";
		input = 0;
		std::cin >> input;
		std::cout << std::endl;

		// If higher, move left boundary up
		if (input == 1)
			left = guess + 1;
		// If lower, move right boundary down
		if (input == 2)
			right = guess - 1;
	}

	// If the loop breaks and we have not returned a number, the user must have cheated
	std::cout << "You cheated! I can't find your number!\n";
}

int main()
{
	// Run forever
	while (true)
	{
		// Clear the screen
		system("cls");

		// State prime directive
		std::cout << "Welcome to the number guessing game!\n";
		std::cout << "I will use a binary search algorithm to attempt to guess your number!\n";
		std::cout << "I need a range to guess between! Please input a\n";

		// As for minimum
		std::cout << "Minimum: ";
		int min = 0;
		std::cin >> min;

		// Ask for maximum
		std::cout << "Maximum: ";
		int max = 0;
		std::cin >> max;
		std::cout << std::endl;

		// Ask for a number in bounds
		std::cout << "And finally, think of a number between " << min << " and " << max << std::endl;
		std::cout << std::endl;

		// Do the search
		BinarySearch(min, max);

		system("pause");
	}
	return 0;
}