routine printDivisors(x : integer) : integer is
    print "Number ";
    print x;
    print " has additional divisors:";
    for i in 2 .. x - 1 loop
        if (x % i) = 0 then
            print " ";
            print i;
        end
    end
    println ".";
    return 0;
end

routine main() : integer is
	var size : integer is 20;
    var prime : array[size] integer;
    prime[1] := 0;
	
    for s in 1 .. size loop
        prime[s] := 1;
    end

    var p : integer is 2;
    while p * p <= size loop
        if prime[p] = 1 then
            for i in (p + 1) .. size loop
                if (i % p) = 0 then
                    prime[i] := 0;
                end
            end
        end
        p := p + 1;
    end

    print "Prime numbers below ";
    print size;
    println " are:";
    for i in 2 .. size loop
        if prime[i] = 1 then
            print "Number ";
            print i;
            println " is prime.";
        else
            printDivisors(i);
        end
    end

    return 0;
end
