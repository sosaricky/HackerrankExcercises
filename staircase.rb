# Level : Easy

def staircase(n)
    # A loop that takes control over the number of lines written
    for line in (0...n).to_a do
        # This Control number of spaces . spaces_quantity per line =  n-(i+1)
        for j in (0...n-(line+1)).to_a do
            print " "
        end
        # Control number of # . #_quantity per line = i+1        
        for k in (0...line+1).to_a do
            print "#"
        end
        puts 
    end
end

staircase(7)