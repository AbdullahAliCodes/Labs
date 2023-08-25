def optain_card(card):
    value = card[:-1]
    face_cards = {
        "A": [1, 11],
        "J": [10],
        "Q": [10],
        "K": [10]
    }
    try:
        return [int(value)]
    except ValueError:
        return face_cards[value]

def sumofcards(value_ofcard):
    sumof = set(value_ofcard[0])
    for value in value_ofcard[1:]:
        sumof = {sums + card for sums in sumof for card in value if sums + card <= 21}
    return sumof

value_ofcard = []
while True:
    player_input = input()
    if player_input == "end":
        break
    value_ofcard.append(optain_card(player_input))
    
sumof = sumofcards(value_ofcard)
sumof = sorted(sumof)

if not sumof:
    print("Bust!")
elif sumof[-1] == 21 and len(value_ofcard) == 2:
    print("Blackjack!")
else:
    final_option = ' or '.join([str(i) for i in sumof])
    print(final_option)
