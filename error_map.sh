# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_map.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 18:39:17 by user42            #+#    #+#              #
#    Updated: 2021/12/05 14:35:02 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make

DIR=./map_test

ARG=map_valide.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_object.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_exit.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_player.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_collect.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_empty.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_enough_c.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_only_one2.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_only_one.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_too_much_c.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_empty_no_wall_nothing.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_enough_c.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_only_one2.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_only_one.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_too_much_c.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_one_more_empty_line.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_wall_at_left.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_wall_at_right.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character2.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character3.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character.ber
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_name2
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_name.be
echo "\n$ARG : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=no_arg
echo "\n$ARG : "
./so_long | grep --color -A 2 -E "Error|OK"

#ARG=
#echo "\n$ARG : "
#./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

