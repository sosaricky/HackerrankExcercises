# Level : Easy
def birthCakeCandles(candles,numberOfCandles):
    max = candles[0]
    repeatsOfMax = 0
    for candle in candles:
        if(candle > max):
            max = candle
            repeatsOfMax = 1
        elif(candle == max):
            repeatsOfMax += 1
    return repeatsOfMax        

# Examples
candles_1 = [10,2,10,2,10,4,1]
print(birthCakeCandles(candles_1,len(candles_1)))
candles_2 = [19]
print(birthCakeCandles(candles_2,len(candles_2)))