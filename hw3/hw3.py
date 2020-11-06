# Name: Wei Huang
# date: winter 2020
# Project: hw3
# reference:
#https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/


#get the information from file
def get_infor(filename, wt, val):
 #open the file
 with open(filename,'r') as infile:
  for line in infile:
   i = 1
   for word in line.split():
    if i == 1: # first word is weight
     wt.append(int(word,10))
     i = i+1
    else: #second word is value
     val.append(int(word,10))

#bottom-up dynamic origramming algiruthm
def knapsackDP(wt, val, W):
   n = len(wt) #length of array
   dp = [[0 for i in range(W+1)] for i in range(n+1)] #second array to store bottom up
   for i in range(n+1):
      for w in range(W+1):
         if i==0 or w==0:
            dp[i][w] = 0
         elif wt[i-1] > w:
            dp[i][w] = dp[i-1][w]
         else:
            dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
   return dp[n][W]

# main function set the array and get the information from the data.txt file and print result.
def main():
   wt = []
   val = []
   W = 6 #Total weight is
   fileName = "data.txt"
   get_infor(fileName, wt, val)
   result = knapsackDP(wt, val, W)

#print result
   print("Given weights:",wt) #print weight from the data.txt
   print("Given Values:",val)#print value from the data.txt
   print("Given total weight:",W) #print total weight
   print("Maximum value can be: ",result) #print resulit by bottom-up dynamic origramming algiruthm
main()
