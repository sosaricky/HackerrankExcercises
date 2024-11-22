# Level :  Easy
# Author : RaulSosa
# Status : Solved
def birthCakeCandles(candles,numberOfCandles)
    max = candles[0]
    repeatsOfMax = 1
    candles.each do |candle|
        if(candle > max) then
            max = candle
            repeatsOfMax = 1
        elsif(candle == max) then
            repeatsOfMax += 1
        end
    end
    return repeatsOfMax
end
candles_1 = [10,10,2,2,24,4,12,24,24]

puts birthCakeCandles(candles_1,candles_1.length())
