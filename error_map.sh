# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_map.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 18:39:17 by user42            #+#    #+#              #
#    Updated: 2021/09/07 19:29:17 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make

DIR=./map_test

ARG=map_valide.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_without_object.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_without_exit.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_without_player.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_without_collect.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_empty.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E -E "Error|OK"

ARG=map_first_line_not_enough_c.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_first_line_not_only_one2.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_first_line_not_only_one.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_first_line_too_much_c.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_last_line_empty_no_wall_nothing.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_last_line_not_enough_c.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_last_line_not_only_one2.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_last_line_not_only_one.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_last_line_too_much_c.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_one_more_empty_line.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_without_wall_at_left.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_without_wall_at_right.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_wrong_character2.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_wrong_character3.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_wrong_character.ber
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_wrong_name2
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=map_wrong_name.be
echo -n "\n$ARG : "
./so_long $DIR/$ARG | grep --color -E "Error|OK"

ARG=no_arg
echo -n "\n$ARG : "
./so_long | grep --color -E "Error|OK"

#ARG=
#echo -n "\n$ARG : "
#./so_long $DIR/$ARG | grep --color -E "Error|OK"

