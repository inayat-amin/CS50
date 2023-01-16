def main():
    card_number = input("Number: ")
    while True:
        if (card_number.isdigit()):
            validity = str(checksum(card_number))
            if (int(validity[len(validity) - 1]) == 0):
                if((len(card_number) == 15) and int(card_number[0]) == 3 and (int(card_number[1]) == 4 or int(card_number[1]) == 7)):
                    print("AMEX")
        
                elif((len(card_number) == 16) and int(card_number[0]) == 5 and (int(card_number[1]) == 1 or int(card_number[1]) == 2 or int(card_number[1]) == 3 or int(card_number[1]) == 4 or int(card_number[1]) == 5)):
                    print("MASTERCARD")
        
                elif(((len(card_number) == 16) or (len(card_number) == 13)) and int(card_number[0]) == 4):
                    print("VISA")
                else:
                    print("VALID CARD NOT RECOGNISED BITCHASS TF YOU DOIN")
            else:
                print("INVALID")
            
            break
        else:
            card_number = input("Number: ")
    
def checksum(card_number):
    checksum_number = 0
    doubled_number = list()
    
    #first check if the length of the number is even:
    if (len(card_number) % 2 == 0):
        
        #Copy each of the elements you want to double into the doubled_number list:
        for i in range(0, len(card_number), 2):
            doubled_number.append(2 * int(card_number[i]))
            
        #Add all the digits in the doubled_number list into the checksum_number variable:
        for i in range(len(doubled_number)):
            
            #check if an element in the doubled_number list has double digits (if so then add the induvidual digits):
            if (doubled_number[i] > 9):
                double_digit_number = str(doubled_number[i])
                for k in range(len(double_digit_number)):
                    checksum_number += int(double_digit_number[k])
            else:
                checksum_number += doubled_number[i]
        
        #Add checksum_number to the rest of the digits of the card number and update checksum_number:
        for i in range(1, len(card_number), 2):
            checksum_number += int(card_number[i])
    
    #if length of the number is odd:
    else:
        #Copy each of the elements you want to double into the doubled_number list:
        for i in range(1, len(card_number), 2):
            doubled_number.append(2 * int(card_number[i]))
            
        #Add all the digits in the doubled_number list into the checksum_number variable:
        for i in range(len(doubled_number)):
            
            #check if an element in the doubled_number list has double digits (if so then add the induvidual digits):
            if (doubled_number[i] > 9):
                double_digit_number = str(doubled_number[i])
                for k in range(len(double_digit_number)):
                    checksum_number += int(double_digit_number[k])
            else:
                checksum_number += doubled_number[i]
        
        #Add checksum_number to the rest of the digits of the card number and update checksum_number:
        for i in range(0, len(card_number), 2):
            checksum_number += int(card_number[i])
        
    print(f"checksum = {checksum_number}")
    
    return(checksum_number)
 

#if __name__ == "__main__":
main()
