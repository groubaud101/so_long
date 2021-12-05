# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_map.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 18:39:17 by user42            #+#    #+#              #
#    Updated: 2021/12/05 15:58:01 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make

DIR=./map_test

GREEN='\033[0;32m'
NC='\033[0m'

ARG=map_valide.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_object.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_exit.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_player.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_collect.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_empty.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_enough_c.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_only_one2.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_not_only_one.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_first_line_too_much_c.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_empty_no_wall_nothing.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_enough_c.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_only_one2.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_not_only_one.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_last_line_too_much_c.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_one_more_empty_line.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_wall_at_left.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_without_wall_at_right.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character2.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character3.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_character.ber
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_name2
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=map_wrong_name.be
echo "\n${GREEN}$ARG${NC} : "
./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

ARG=no_arg
echo "\n${GREEN}$ARG${NC} : "
./so_long | grep --color -A 2 -E "Error|OK"

#ARG=
#echo "\n${GREEN}$ARG${NC} : "
#./so_long $DIR/$ARG | grep --color -A 2 -E "Error|OK"

