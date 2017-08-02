#!/usr/bin/python

choice = 0
cur_val_pow = 0
min_val_pow = 0
max_val_pow = 9750
cur_pct_pow = 0
min_pct_pow = 0
max_pct_pow = 100

while choice != -1:
    choice = int(input('Are you entering a (1) Power Percentage or a (2) Power Value? (Enter -1 to quit): '))
    if choice == -1:
        break
    elif choice == 1:
        while (cur_pct_pow != -1):
            cur_pct_pow = int(input('Enter a power percentage between ' + str(min_pct_pow) + ' and ' + str(max_pct_pow) + ' (or -1 to return to input type selection): '))
            if cur_pct_pow == -1:
                break
            elif cur_pct_pow > max_pct_pow or cur_pct_pow < min_pct_pow:
                print('Invalid percentage entered. Percentage must be between ' + str(min_pct_pow) + ' and ' + str(max_pct_pow) + '. Please try again.')
            else:
                pct_to_val = (cur_pct_pow * max_val_pow) / max_pct_pow
                print('Power Value: ' + str(pct_to_val))
    elif choice == 2:
        while (cur_val_pow != -1):
            cur_val_pow = int(input('Enter a power value between ' + str(min_val_pow) + ' and ' + str(max_val_pow) + ' (or -1 to return to input type selection): '))
            if cur_val_pow == -1:
                break
            elif cur_val_pow > max_val_pow or cur_val_pow < min_val_pow:
                print('Invalid value entered. Value must be between ' + str(min_val_pow) + ' and ' + str(max_val_pow) + '. Please try again.')
            else:
                val_to_pct = (200*cur_val_pow + max_val_pow) / (2*max_val_pow)
                print('Power Percentage: ' + str(val_to_pct))
    else:
        print('Invalid choice entered. Please try again or enter -1 to quit.')
