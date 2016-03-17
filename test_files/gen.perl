# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gen.perl                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/08 04:30:06 by knzeng-e          #+#    #+#              #
#    Updated: 2016/03/08 04:30:33 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "o";
        }
        else {
            print ".";
        }
    }
    print "\n";
}
