#!/usr/bin/env ruby
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 18:11:55 by fokrober          #+#    #+#              #
#    Updated: 2020/02/04 18:11:55 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require 'pry'
require 'open3'

class Parser
	attr_accessor :dim

	@got_lines = 0
	@dim = {:rows => 0, :cols => 0}
	File.open("filler.map", "w") do |f|
		data = File.open("filler.data", "w")
		ARGF.read.each_line do |file|
			line = file.to_s
			if (@got_lines == 0 || @got_lines < @dim[:rows].to_i)
				if (res = line.match (/^\${3} exec p(?<p>\d+) : \[(?<pname>.*)\]/))
					data.puts "#{res[:p]} #{res[:pname].split('/').last}"
				elsif (res = line.match /^Plateau (?<rows>\d+) (?<cols>\d+)/)
					data.puts "#{res[:rows]} #{res[:cols]}"
					@dim[:rows] = res[:rows]
					@dim[:cols] = res[:cols]
				elsif (line.match?(/^\d{3} [.oOxX]+[\n]?/))
					line.sub(/\d+ /, '').each_char do |c|
						f.write "#{".oOxX".rindex c}  "
					end
					f.puts ""
					@got_lines += 1
				end
			end
			if (res = line.match /.*\*.*/)
				data.puts res
			elsif (res = line.match /.+got \((?<p>.)\): \[(?<y>\d+), (?<x>\d+)\]/)
				data.puts "#{res[:p]} #{res[:x]} #{res[:y]}"
			end
		end
		data.close
	end
	begin
		@stdin, @stdout, @wait_thr = Open3.popen2("./fdf/fdf", "filler.map")
		puts "launched viz"
	rescue
		puts "error:"
		puts "bad visualizer"
		exit (-3)
	end
end
