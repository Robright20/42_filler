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
	attr_accessor :maps_nb, :dim, :visualizer

	File.open("log.txt", "w") do |f|
		@maps_nb = 0
		ARGF.read.each_line do |file|
			line = file.to_s
			if line.match?(/Plateau \d+ \d+/)
				@dim = line.match /(?<height>\d+) (?<width>\d+)/
				f.write "\n" unless @maps_nb == 0
				count = @dim[:width].to_i
				@maps_nb += 1
			end
			if line.match?(/^\d{3} [.oOxX]+[\n]?/)
				if (count != 0)
					f.write line.sub /\d+ /, ''
				end
				if count != nil
					count -= 1;
				end
			end
		end
	end
	begin
		@stdin, @stdout, @wait_thr = Open3.popen2("./viz/viz", "log.txt",
													  @maps_nb.to_s,
													  @dim[:height].to_s,
													  @dim[:width].to_s)
		puts "launched viz"
	rescue
		puts "error:"
		puts "bad visualizer"
		exit (-3)
	end
end
