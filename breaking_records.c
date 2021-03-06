/* Question: Maria plays  games of college basketball in a season. Because she wants to go pro, she tracks her points scored per game sequentially in an array defined as . After each game , she checks to see if score  breaks her record for most or least points scored so far during that season.

Given Maria's array of  for a season of  games, find and print the number of times she breaks her record for most and least points scored during the season.

Note: Assume her records for most and least points at the start of the season are the number of points scored during the first game of the season.

Input Format

The first line contains an integer denoting  (the number of games). 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print two space-seperated integers describing the respective numbers of times her best (highest) score increased and her worst (lowest) score decreased.

Sample Input 0

9
10 5 20 20 4 5 2 25 1
Sample Output 0

2 4
Explanation 0

The diagram below depicts the number of times Maria broke her best and worst records throughout the season:

image

She broke her best record twice (after games  and ) and her worst record four times (after games , , , and ), so we print 2 4 as our answer. Note that she did not break her record for best score during game , as her score during that game was not strictly greater than her best record at the time.

Sample Input 1

10
3 4 21 36 10 28 35 5 24 42
Sample Output 1

4 0
Explanation 1

The diagram below depicts the number of times Maria broke her best and worst records throughout the season:

image

She broke her best record four times (after games , , , and ) and her worst record zero times (no score during the season was lower than the one she earned during her first game), so we print 4 0 as our answer. */

// Complexity O(n)
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* getRecord(int s_size, int* s, int *result_size){
    // Complete this function
	// Simply calculating max and min and how many
	// times this has changed will give is the number
	// of breaking records and lowest one too
    int max = s[0], min = s[0];
    int count_high = 0, count_low = 0;
    for(int i=1; i<s_size; i++){
        if(max < s[i]){
           max = s[i];
            count_high++;
        }
        
        if(min > s[i]){
           min = s[i];
           count_low++; 
        }
    }

    int *result = (int *)malloc(sizeof(int) * 2);
    memset(result, 0, sizeof(int) * 2);
    
    *result_size = 2;
     result[0] = count_high;
     result[1] = count_low;
    
    return result;
}

int main() {
    int n; 
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
       scanf("%d",&s[s_i]);
    }
    int result_size;
    int* result = getRecord(n, s, &result_size);
    for(int i = 0; i < result_size; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    puts("");
    return 0;
}

