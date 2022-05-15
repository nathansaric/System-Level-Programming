/* NATHAN SARIC - 10/23/2020 
 *
 * Script 1: diving.c
 * This program accepts a degree of difficulty followed by eight judge scores from the user,
 * and computes the score for a dive accordingly.
 */

#include <stdio.h>

#define MINSCORE 0
#define MAXSCORE 10
#define MINDEGREE 1
#define MAXDEGREE 5
#define NUMJUDGES 8

float scanDegreeOfDifficulty() {
  float degreeOfDifficulty;
  printf("degree of difficulty: ");
  scanf("%f", &degreeOfDifficulty);

  //ERROR HANDLING:
  //If the degree of difficulty is less than 1 or greater than 5.
  if (degreeOfDifficulty < MINDEGREE || degreeOfDifficulty > MAXDEGREE) {
    printf("Error: degree of difficulty must be between 1 and 5\n");
    printf("Using 1 as default degree of difficulty\n");
    degreeOfDifficulty = 1;
  }
  return degreeOfDifficulty;
}

float scanJudgeScores(int numJudge) {
  float judgeScore;
  printf("enter score from judge %d: ", ++numJudge);
  scanf("%f", &judgeScore);

  //ERROR HANDLING:
  //If the score is less than 0 or greater than 10.
  if (judgeScore < MINSCORE || judgeScore > MAXSCORE) {
    printf("Error: judge score must be between 0 and 10\n");
    printf("Using 0 as default judge score\n");
    judgeScore = 0;
  }
  return judgeScore;
}

float computeScore(float judgeScores[]) {
  int i, j;
  int temp = 0;
  float score = 0;
  float tempScore = 0;

  //Sorting the array in ascending order
  for (i = 0; i < NUMJUDGES; i++) {
    for (j = i + 1; j < NUMJUDGES; j++) {
      if (judgeScores[i] > judgeScores[j]) {
        temp = judgeScores[i];
        judgeScores[i] = judgeScores[j];
        judgeScores[j] = temp;
      }
    }
  }

  for (i = 0; i < NUMJUDGES; i++) {
    tempScore += judgeScores[i];
  }

  float highestScore = judgeScores[7];
  float secondHighestScore = judgeScores[6];
  float lowestScore = judgeScores[0];
  float secondLowestScore = judgeScores[1];

  score = (tempScore - highestScore - secondHighestScore - lowestScore - secondLowestScore);
  return score;
}

float computeFinalScore(float score, float degreeOfDifficulty) {
  float finalScore = (score * degreeOfDifficulty);
  return finalScore;
}

int main() {
  float degreeOfDifficulty = scanDegreeOfDifficulty();
  float judgeScores[NUMJUDGES];
  int i;

  for (i = 0; i < NUMJUDGES; ++i) {
    judgeScores[i] = scanJudgeScores(i);
  }

  float score = computeScore(judgeScores);
  float finalScore = computeFinalScore(score, degreeOfDifficulty);
  printf("Score for this dive is %.2f\n", finalScore);

  return 0;
}
