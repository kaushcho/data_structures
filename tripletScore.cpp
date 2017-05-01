#include <iostream>

class Score 
{
private:
	int m_problemClarityScore;
	int m_originalityScore;
	int m_difficultyScore;
	int m_pointsAwarded;
public:
	Score();
	Score(int a, int b, int c);
	void CompareScore(Score& b);
	void PrintPoints();
	void PrintScore();

};

Score::Score()
{
	m_pointsAwarded = 0;
	m_difficultyScore = 0;
	m_originalityScore = 0;
	m_problemClarityScore = 0;
}
Score::Score(int a, int b, int c)
{
	m_problemClarityScore = a;
	m_originalityScore = b;
	m_difficultyScore = c;
}
void Score::CompareScore(Score& b)
{
	m_pointsAwarded = 0;
	b.m_pointsAwarded = 0;

	if (m_problemClarityScore < b.m_problemClarityScore)
		b.m_pointsAwarded++;
	else if (m_problemClarityScore > b.m_problemClarityScore)
		m_pointsAwarded++;

	if(m_originalityScore < b.m_originalityScore)
		b.m_pointsAwarded++;
	else if (m_originalityScore > b.m_originalityScore)
		m_pointsAwarded++;

	if(m_difficultyScore < b.m_difficultyScore)
		b.m_pointsAwarded++;
	else if (m_difficultyScore > b.m_difficultyScore)
		m_pointsAwarded++;
	
}
void Score::PrintScore()
{
	std::cout << m_problemClarityScore << " " << m_originalityScore << " " << m_difficultyScore << std::endl;
}
void Score::PrintPoints()
{
	std::cout << m_pointsAwarded;
}
int main()
{
	int x1, x2, x3;
	std::cin >> x1 >> x2 >> x3;
	Score Alice(x1, x2, x3);
	x1 = 0, x2 = 0, x3 = 0;
	std::cin >> x1 >> x2 >> x3;
	Score Bob(x1, x2, x3);
	Alice.CompareScore(Bob);
	Alice.PrintPoints();
	std::cout << " ";
	Bob.PrintPoints();
	std::cout << std::endl;

	return 0;
}