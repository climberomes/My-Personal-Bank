#pragma once

namespace TEXT
{
	namespace TEXT_COLORS
	{
		const static int BLACK = 30;
		const static int RED = 31;
		const static int GREEN = 32;
		const static int YELLOW = 33;
		const static int BLUE = 34;
		const static int MAGENTA = 35;
		const static int CYAN = 36;
		const static int WHITE = 37;
	}

	namespace BACKGROUND_COLORS
	{
		const static int BLACK = 40;
		const static int RED = 41;
		const static int GREEN = 42;
		const static int YELLOW = 43;
		const static int BLUE = 44;
		const static int MAGENTA = 45;
		const static int CYAN = 46;
		const static int WHITE = 47;
	}

	namespace TEXT_SETTINGS
	{
		const static int RESET = 0;				//reset everything back to normal
		const static int BRIGHT_ON = 1;			//brighter shade of same color
		const static int UNDERLINE_ON = 4;
		const static int INVERSE_ON = 7;		//swap test and background colors
		const static int BRIGHT_OFF = 21;
		const static int UNDERLINE_OFF = 24;
		const static int INVERSE_OFF = 27;
	}
}