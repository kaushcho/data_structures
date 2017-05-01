#include <iostream>
#include <algorithm>
/* 
 * Test Input: arrival[] = {900, 940, 950, 1100, 1500, 1800}
 * Test Input: departure[] = {910, 1200, 1120, 1130, 1900, 2000}
 * Test Output: 3
 */
int findNumPlatformsRequired(int arrival[], int departure[], int numTrains)
{
	// Sort the arrival and departure arrays separately
	//std::sort(arrival[0], arrival[numTrains]);
	//std::sort(departure[0], departure[numTrains]);

	int platformsNeeded = 1;
	int i = 1, j=0;

	while (i < numTrains && j < numTrains)
	{
		std::cout << arrival[i] << " " << departure[j] << std::endl;
		if(arrival[i] < departure[j])
		{
			platformsNeeded++;
			i++;
		}
	}

	return platformsNeeded;
}

int main()
{
	int arrival[] = {900, 940, 950, 1100, 1500, 1800};
	int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
	int numTrains = sizeof(arrival)/sizeof(arrival[0]);
	int result = 0;
	if (numTrains == sizeof(departure)/sizeof(departure[0]))
		result = findNumPlatformsRequired(arrival, departure, numTrains);
	std::cout << "Minimum number of platforms needed = " << result << std::endl;
	return 0;
}