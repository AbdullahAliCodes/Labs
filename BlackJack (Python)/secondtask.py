card = input()
second_card = input()

value_1 = 0
value_4 = 0

if card == "2c" or card == "2d" or card == "2h" or card == "2s":
    value_1 = 2
elif card == "3c" or card == "3d" or card == "3h" or card == "3s":
    value_1 = 3
elif card == "4c" or card == "4d" or card == "4h" or card == "4s":
    value_1 = 4
elif card == "5c" or card == "5d" or card == "5h" or card == "5s":
    value_1 = 5
elif card == "6c" or card == "6d" or card == "6h" or card == "6s":
    value_1 = 6
elif card == "7c" or card == "7d" or card == "7h" or card == "7s":
    value_1 = 7
elif card == "8c" or card == "8d" or card == "8h" or card == "8s":
    value_1 = 8
elif card == "9c" or card == "9d" or card == "9h" or card == "9s":
    value_1 = 9
elif card == "10c" or card == "10d" or card == "10h" or card == "10s":
    value_1 = 10
elif card == "Ac" or card == "Ad" or card == "Ah" or card == "As":
    value_1 = 1
    value_4 = 11
else:
    value_1 = 10

value_2 = 0
value_3 = 0

if second_card == "2c" or second_card == "2d" or second_card == "2h" or second_card == "2s":
    value_2 = 2
elif second_card == "3c" or second_card == "3d" or second_card == "3h" or second_card == "3s":
    value_2 = 3
elif second_card == "4c" or second_card == "4d" or second_card == "4h" or second_card == "4s":
    value_2 = 4
elif second_card == "5c" or second_card == "5d" or second_card == "5h" or second_card == "5s":
    value_2 = 5
elif second_card == "6c" or second_card == "6d" or second_card == "6h" or second_card == "6s":
    value_2 = 6
elif second_card == "7c" or second_card == "7d" or second_card == "7h" or second_card == "7s":
    value_2 = 7
elif second_card == "8c" or second_card == "8d" or second_card == "8h" or second_card == "8s":
    value_2 = 8
elif second_card == "9c" or second_card == "9d" or second_card == "9h" or second_card == "9s":
    value_2 = 9
elif second_card == "10c" or second_card == "10d" or second_card == "10h" or second_card == "10s":
    value_2 = 10
elif second_card == "Ac" or second_card == "Ad" or second_card == "Ah" or second_card == "As":
    value_2 = 1
    value_3 = 11
else:
    value_2 = 10



if value_1 == 10 and value_2 == 1:
    print("Blackjack!")

elif value_1 == 1 and value_2 == 10:
    print("Blackjack!")

elif value_1 == 1 and value_2 == 1 :
    print(value_1 + value_2, "or", value_1 + value_3)

elif value_1 == 1 :
    print(value_1 + value_2, "or", value_4 + value_2)
   
elif value_2 == 1 :
    print(value_1 + value_2, "or", value_1 + value_3)
    
else:
    print(value_1 + value_2)
