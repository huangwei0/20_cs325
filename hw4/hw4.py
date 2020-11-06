# Name: Wei Huang
# date: winter 2020
# Project: hw4
# reference:
#https://www.chegg.com/homework-help/questions-and-answers/using-c-c-python-part-completed-used-provide-background-consider-problem-making-change-n-c-q44182526


#Return denomination list as power of coin c
def get_denominations(c, k):
    coins = list()
    for i in range(0, k+1):
        coins.append(c**i)
    return coins

#Calculating the denomination and the cardinality needed to change the cardinality
def make_denominations(amount, coins, ans):
    if amount == 0:
        return

    for coin in reversed(coins):
        if coin <= amount:
            cnt = int(amount / coin)
            ans.append((coin, cnt))
            amount = amount - cnt * coin
            make_denominations(amount, coins, ans)
            return

#write the result
def write_formatter(ans):
    output = "{} {}".format(ans[0][0], ans[0][1])
    for a in ans[1:]:
        output += ", {} {}".format(a[0], a[1])
    return output + "\n"

#open the file and write the infomation into the file
def driver(input_file_name, output_file_name):
    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'a')
    input_data = input_file.readlines()

    for i in input_data:
        c, k, n = i.split(" ")

        # get denominations of input
        coins = get_denominations(int(c), int(k))
        ans = []
        n.strip('\n')
        make_denominations(int(n), coins, ans)

        # write output to the file
        output_file.write(write_formatter(ans))

    input_file.close()
    output_file.close()

driver("data.txt", "change.txt")
