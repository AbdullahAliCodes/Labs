import itertools

FACE_CARDS = {
    "A": [1, 11],
    "J": [10],
    "Q": [10],
    "K": [10],
}

def card_value(card):
    value = card[:-1]
    if value.isdigit():
        return [int(value)]
    else:
        return FACE_CARDS[value]

def card_values(cards):
    return [card_value(card) for card in cards]

def card_sum(cards):
    possible_sums = set([0])
    for card in cards:
        new_sums = set()
        for possible_sum in possible_sums:
            for value in card:
                new_sums.add(possible_sum + value)
        possible_sums = {s for s in new_sums if s <= 21}
        if not possible_sums:
            break
    return possible_sums or {min(new_sums)}

player_cards = input().split()
dealer_cards = input().split()

player_sums = card_sum(card_values(player_cards))
dealer_sums = card_sum(card_values(dealer_cards))

if max(player_sums) > max(dealer_sums):
    print("Player wins!")
elif max(dealer_sums) > max(player_sums):
    print("Dealer wins!")
else:
    print("Push!")
