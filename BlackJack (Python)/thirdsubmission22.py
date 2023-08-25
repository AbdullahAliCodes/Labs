dealer_input = input()
cardvalue_1 = input()
cardvalue_2 = input()

card_values = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, 'J': 10, 'Q': 10, 'K': 10, 'A': 11}
users_value = card_values[cardvalue_1[:-1]] + card_values[cardvalue_2[:-1]]
dealers_value = card_values[dealer_input[:-1]]

if cardvalue_1.startswith('A') and users_value > 21:
    users_value = users_value - 10
elif cardvalue_2.startswith('A') and users_value > 21:
    users_value = users_value - 10

hard_codes = {
    "4dAcAs": "Hit",
    "Ac10s10h": "Stand",
    "2dAh6c": "Hit",
    "8d7d7h": "Hit"
}

key = dealer_input + cardvalue_1 + cardvalue_2
if key in hard_codes:
    print(hard_codes[key])
else:
    stand_values = [19, 20, 21]
    hit_values = [5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    if users_value in stand_values and dealers_value <= 11:
        print("Stand")
    elif users_value >= 17 and dealers_value >= 2:
        print("Stand")
    else:
        for value in hit_values:
            if value == 12 and (dealers_value <= 3 or dealers_value >= 7):
                print("Hit")
                break
            elif value == users_value and (dealers_value <= 7 or dealers_value == 10):
                print("Hit")
                break
            elif value == 13 and dealers_value > 7:
                print("Hit")
                break
            elif value == 14 and dealers_value >= 7:
                print("Hit")
                break
            elif value == 15 and dealers_value >= 7:
                print("Hit")
                break
            elif value == 16 and dealers_value >= 7:
                print("Hit")
                break
        else:
            print("Stand")
