#!/bin/bash

WIDTH=${1:-15}
HEIGHT=${2:-10}
NUM_COLLECTIBLES=${3:-5}
OUTPUT_FILE="maps/map_$(date +%s).ber"

generate_map() {
    local w=$1
    local h=$2
    local collectibles=$3

    declare -a map
    for ((y=0; y<h; y++)); do
        map[$y]=""
        for ((x=0; x<w; x++)); do
            if [ $y -eq 0 ] || [ $y -eq $((h-1)) ] || [ $x -eq 0 ] || [ $x -eq $((w-1)) ]; then
                map[$y]="${map[$y]}1"
            else
                if [ $((RANDOM % 100)) -lt 20 ]; then
                    map[$y]="${map[$y]}1"
                else
                    map[$y]="${map[$y]}0"
                fi
            fi
        done
    done

    while true; do
        px=$((RANDOM % (w-2) + 1))
        py=$((RANDOM % (h-2) + 1))
        char="${map[$py]:$px:1}"
        if [ "$char" = "0" ]; then
            map[$py]="${map[$py]:0:$px}P${map[$py]:$((px+1))}"
            break
        fi
    done

    while true; do
        ex=$((RANDOM % (w-2) + 1))
        ey=$((RANDOM % (h-2) + 1))
        char="${map[$ey]:$ex:1}"
        if [ "$char" = "0" ] && ! ([ $ex -eq $px ] && [ $ey -eq $py ]); then
            map[$ey]="${map[$ey]:0:$ex}E${map[$ey]:$((ex+1))}"
            break
        fi
    done

    placed=0
    max_attempts=1000
    attempts=0
    while [ $placed -lt $collectibles ] && [ $attempts -lt $max_attempts ]; do
        cx=$((RANDOM % (w-2) + 1))
        cy=$((RANDOM % (h-2) + 1))
        char="${map[$cy]:$cx:1}"
        if [ "$char" = "0" ]; then
            map[$cy]="${map[$cy]:0:$cx}C${map[$cy]:$((cx+1))}"
            placed=$((placed + 1))
        fi
        attempts=$((attempts + 1))
    done

    if [ $placed -lt $collectibles ]; then
        echo "Attention: Seulement $placed collectibles placés sur $collectibles demandés"
    fi

    for ((y=0; y<h; y++)); do
        echo "${map[$y]}" >> "$OUTPUT_FILE"
    done
}

echo "Génération d'une map ${WIDTH}x${HEIGHT} avec ${NUM_COLLECTIBLES} collectibles..."
generate_map $WIDTH $HEIGHT $NUM_COLLECTIBLES

echo "Map générée: $OUTPUT_FILE"
echo "Contenu de la map:"
cat "$OUTPUT_FILE"
echo ""
echo "Pour tester: ./so_long $OUTPUT_FILE"
